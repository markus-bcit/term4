# Tasks 1

Big hint, look at the Ansible docs on ad hoc commands linked below!

- Write an ad hoc command that will display the kernel version of the "db"
  servers. (hint `uname`).
```bash
 ansible db -a "uname --version"
```
- Write an ad hoc command that will install nginx on the web servers. (hint
  Ansible has a number of package modules, including an apt module)
```bash
ansible web -m apt -a "name=nginx" --become --become-user=root
```
- Create a 'file' directory and add the HTML document below as 'index.html'.
  Then write an ad hoc command that will copy your local 'index.html' to the
  `/var/www/html` directory on your web servers. (hint copy module)
```bash
ansible web -m ansible.builtin.copy -a "src=/home/markus/4640/week05_vpc/index.html dest=/var/www/html/index.html" --become --become-user=root
```
- write an ad hoc command that will restart the nginx service. (hint service
  module)
```bash
ansible web -m ansible.builtin.service -a "name=nginx state=restarted" --become --become-user=root
```
- Finally visit one of your web servers in the browser to confirm that you are
  serving HTML document below instead of the default nginx page.
  ![[Pasted image 20240206163623.png]]
- What does "Idempotent" mean? What does this mean in the context of an Ansible
  ad hoc command?
  
  > if you send multiple identical requests, only the initial request would cause a change [src](https://blog.hubspot.com/website/idempotent-api#:~:text=When%20an%20HTTP%20method%20is,the%20method%20has%20been%20called)

In the context of ansible, if we did multiple of the same task, only the first one will be executed.
# Task 2
## Ansible playbook

```yml
---
- name: web - install nginx, change default html, restart nginx
  hosts: web
  tasks:
    - name: install nginx package
      ansible.builtin.package:
        name: nginx
        state: latest
    - name: copy html
      ansible.builtin.copy:
        src: /home/markus/4640/week05_vpc/index.html
        dest: /var/www/html/index.html
    - name: restart nginx service
      become: true
      ansible.builtin.service:
        name: nginx
        state: restarted


- name: db install mysql
  hosts: db
  tasks:
    - name: insatll mysql server
      become: true
      apt:
        name: mysql-server
        state: latest

- name: install bum
  hosts: backend
  tasks:
    - name: Install unzip on backend servers
      become: true
      apt:
        name: unzip
        state: present
    - name: Install bun on backend servers
      become_user: ubuntu
      shell:
        cmd: "curl -fsSL https://bun.sh/install | bash"
```