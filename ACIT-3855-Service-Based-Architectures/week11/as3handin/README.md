Video: https://youtu.be/o1KeDtrzseY

## Steps to run:
- Apply the state in terraform/state
- Apply the infrastructure in terraform/infra
- Replace the ip in ansible/roles/frontend/files/hello.conf line 20
- Run the ansible playbook `ansible-playbook web.yml`