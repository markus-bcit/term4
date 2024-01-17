# Week1
- #outline 
  - | Type | % | Desc. |
    | --- | --- | --- |
    | Quizzes | 15% |There will be a quiz at the beginning of each class (except the first and last) | 
    | Project Labs | 35% | The full enterprise software development environment will be incrementally built through the labs. Includes a participation component |
    | Assignments | 15% |There will be 3 assignments, two individual and one with your partner|
    | Final Exam | 35% | |
    - Quizzes will only be done in-class only. There are no late or make-up quizzes, but the lowest quiz of the term will be dropped. There is a 20% penalty per week for late lab submissions, up to a maximum of 2 weeks.
	- Passing Criteria:  
		- Students must complete a minimum of 80% of the Project Labs.
		- Students must achieve a minimum of 50% on the combination of the Quizzes and Final Exam (i.e., 27.5/55).  
		- Students must achieve an overall grade of at least 50% in the course.  

Typically leverages specific terms #terms: 
- shall: Requirement is contractually binding, meaning it must be implemented and verified
- will: Statement of fact. Not subject to verification. 
- should: Goals, non-mandatory vision. Typically a goal which must be addressed by the design team but is not formally verified.
# week 2
#reading
# Work Management and Knowledge Base Tools

>  Work Management Work Management Software is crucial for software teams to plan, track, organize, and review their work. Typically organized around projects or ongoing tasks, a project represents work to produce a specific outcome within a defined scope and timeframe. Agile workflows with Kanban boards are common in these tools, and popular examples include Trello, Asana, GitHub, GitLab, and JIRA by Atlassian. JIRA supports both traditional waterfall and agile workflows and is highly configurable. Installation methods for JIRA on Linux can be found [here](https://confluence.atlassian.com/adminjiraserver/installing-jira-applications-on-linux-938846841.html). 
## Knowledge Base 

> A knowledge base serves as a repository for documentation relevant to a software team and product. It includes team processes, development processes, software design, architecture, and operational instructions. While a knowledge base can be a shared folder, there are tools to manage documentation effectively. Examples include SharePoint, Wikis (e.g., MediaWiki, GitHub, GitLab), and Confluence by Atlassian. Confluence stands out with its robust search capability and a WYSIWYG editor. Installation methods for Confluence on Linux can be found [here](https://confluence.atlassian.com/doc/installing-confluence-on-linux-143556824.html).

Assignment 1 will be evaluating tools against different types of requirements 
- This will be due around week five 

For installing Jira ○ Will use Work Management capabilities 
- Use the Work Management capabilities 
- Both Confluence and Jira are made by Atlassian and both use Java
- Make sure to open up port 88 to use JIRA 
	- To connect to to MySQL from jira use localhost:3306 And port 22 for the SSH access 
- The goal of this is to feel the pain 
- tail -f <log filename> will show active running logs 
- Tail <n> will show the last n logs 
	- There are commands for starting and stopping the services, DON’T JUST SYSTEMCTL IT 
	- Jira installation folder should also be /opt/atlassian/jira