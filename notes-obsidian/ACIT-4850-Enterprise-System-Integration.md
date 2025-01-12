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
- tail -f log filename will show active running logs 
- Tail n will show the last n logs 
	- There are commands for starting and stopping the services, DON’T JUST SYSTEMCTL IT 
	- Jira installation folder should also be /opt/atlassian/jira

#helpful
- Final Notes

**Class Notes:**

●       The final will be written - on paper closed book within half an hour

○       Probably worth only about a ¼

●       Then we can do the final exam quiz which will have a few of the written and the pipeline

○       There are some pipelines with Java or Python

○       We will need to make a repo with that pipeline

○       There will be about 5 stages

●       Part 2 is open book

●       There are 2 hours to do all of it

●       More details on the first part:

○       General questions - multiple choice, true/false, multi-select, short answer

○       What to know:

■       Enterprise development environment - what is it and what are the parts we covered

■       Tools - what does each do?

■       Concepts - DevOps (ie, CI/CD)

■       Jenkinsfile/Shared library - what are the parts jenkinsfile and why is it good? What is a shared Library and why is it good?

■       Jenkins vs GitLab CI - Similarities and Differences

■       On Prem VS Cloud - What are they? When would you use one over the other?

■       Development Workflows - truck based vs feature based

■       Tool Assessments - Scenario Based, Written answers:

●       For example the project manager may care about money, the team familiarity

●       IT team may care about support and security

●       Dev team may care about learning curve, or efficiency

●       Part 2:

○       Could be jenkins or gitlab CI

○       Keep it simple and stick to the stuff we did in class

○       Description of the stages will be given

■       There will probably be about 5

○       Zipfile with the source code will be given (Java or Python)

○       We will need pylint and zip set up

○       We will not need docker, sonarQube, Nexus, JIRA, Confluence

○       You will need a source code management tool (ie. Gitlab) to store the source code and jenkinsfile

○       We will not need a shared library - these will be GitLab CI .gitlab-ci.yml or Jenkinsfile command

Concepts:

●       Stakeholders:

○       Consider what is important to the following stakeholders when making a product selection for our enterprise development environment

■       Software Developers

●       May care about usability

■       Project managers:

●       Adoption

●       Cost

■       Team Lead:

●       Adoption

●       Team option

■       IT operations

●       Scalability

●       Security

●       Support

●       Improvements:

○       What improvements would you make to our Enterprise development environment with regards to:

■       Security

●       Limit access, maybe use a VPN to access these tools behind a network

●       MFA tokens

●       Limit any open ports

●       Encrypt data in transit

●       Use single sign-on with centralized auto

■       Usability:

●       Single sign-on

●       Knowledge base with links to tools

●       A library of pre-made templates that can be used to get started with a new project

■       Upgrade and Maintenance

●       Backups

○       SLA - service level agreement

○       How long can we lose before we can get back

○       This can also impact uptime

●       There should be some agreement on how often we upgrade the tools

■       CI/CD Infrastructure:

●       We could have a cluster that runs different application as part of the CD where it can be deployed automatically

Quiz One:

1. Why would we want to integrate Enterprise Systems? Select the best answer.

-        To improve efficiency

2.  Define Enterprise. Select the best answer

-        Business or Company

3.  Define the three characteristics of on-premise infrastructure from the list below

-        Capital Expense

-        Controlled By Your Organization

-        Pay upfront

4. Define the three characteristics of cloud infrastructure from the list below

-        Controlled by a 3rd party

-        Pay as you go

-        Operational expense

5. Your IT Team has been tasked with replacing an existing Subversion source code management tool with a new Git based tool. They want to use a Cloud based Software As a Service option. Your team lead has asked you to assess the top three products on the market: BitBucket, GitHub and GitLab.

Identify three areas where you would want to compare these products and why?

Cost - Since the goal of the company is likely to make money it is importaint to consider any new costs that might be envolved with making a switch to a new system. Things to consider here are cost per user, the long term support for the system, upfront charges, and the relative cost for the use of the system compared to the others. This is importaint for a cloud system as pay as you go costs may also be higher.

Familiarity - If the team is already familiar or has a preference for one of these tools, it would be ideal to consider that, so future users of the system will be more willing to learn or use it.

Support - Does the company need to support this tool or is it owned and supported by a 3rd party if so does that third party make active changes to fix bugs? This can be importaint to consider since it could leave the company with a tool that no longer works if it no longer has support.

6. Which installation methods do you have for a production installation of confluence or JIRA?

-        Docker Containers

-        Installer - Linux

-        Cluster (High-availability)

-        Installer - Windows

-        Zip or Archive File

(note this question was everything except for Installer - Mac)

7. What database options do you have for a production installation of JIRA or Confluence? Select all that apply

-        Oracle

-        PostgreSQL

-        MySQL

-        Microsoft SQL Server

(note this was everything except for Embedded H2)

8. What capabilities does Confluence provide?

-        Knowledge Base

Quiz Two:

1. Select the best definition of a Non-functional requirement

-        Defined constraints on the design or implementation of a system or its component

2. Select the best defining of a functional requirement

-        Defines a function of a system or its components

3. Which of the following are examples of functional requirement(s)?

-        The System should bill the users credit card immediately after the user confirms their order

4. For functional requirements, a function is described as a specification of behaviour between output and inputs

-        True

5.  Functional requirements may involve calculations, technical details, data manipulation and processing, and other specific functionality that define what a system is supposed to accomplish

-        True

6. Non-functional requirements are also referred to as System Quality attributes

-        True

7. Which of the following would be considered examples of Non-functional requirement(s)?

-        A web application should work on the Chrome, Firefox, and Safari browsers

-        A web application should be capable of enough to handle 2 million concurrent users without affecting its performance

8.  Which of the following are categories of Non-functional requirements? Select all that apply

-        Security

-        Scalability

-        Availability

-        Usability

-        Testability

-        Maintainability

9.  Non-functional requirements are also referred to as architecturally significant requirements

-        True

10. Non-functional requirements are also referred to as “ilities”

-        True

Quiz 3:

1. The following is a practical definition of DevOps:

DevOps is the practice of operations and development engineers participating together in the entire service lifecycle, from the design through the development process to production support.

-        True

2.  Identify the three primary practice areas of DevOps

-        Infrastructure Automation

-        Continuous Delivery

-        Site Reliability Engineering

3. Infrastructure automation refers to creating your systems, OS configs, and app deployments as code. This code is stored in a source code management system.

-        True

4. Continuous Delivery means having developers and operations engineers manually build, test, and deploy your app daily.

-         False

5. Site Reliability Engineering includes operating your systems; monitoring and orchestration. It also includes designing for operability in the first place

-        True

6. What should go in your project’s single source code repository?

-        Test Scripts

-        Code

-        Database schema

-        Install Scripts

7.  A continuous integration server is where (select the best answer):

-        A build is run automatically every time the code changes

8. Frequently committing to the mainline in the source code repository helps developers quickly find out if there’s a conflict between two developers (in terms of their code changes)

-        True

9. When a build breaks, "nobody has a higher priority task than fixing the build" (Kent Beck). This means that all developers on the team should immediately focus on fixing the build.

-        False

10. Which of the following are important characteristics of a good Continuous Integration pipeline?

-        Visibility (of the status)

-        Automated Build        

-        Automated Tests

-        Fast Build and Test

-        Runs on Every Checkin to the Source Code Repository

11.  A stakeholder is anyone that has an interest (or concern) in the realization of the system or tools you are evaluating and planning to bring into the enterprise. The interests of your stakeholders may include features, cost, deployment, operations.

-        True

12. From the following list, who would most likely be considered stakeholders (or stakeholder groups) for our Enterprise Development Environment?

-        Test Team

-        IT Operations team

-        Project Manager (PM)

-        Development Team

Quiz 4:

1. The definition of a Jenkins pipeline is written in a text file. What is this text file called?

-        Jenkinsfile

2. What are the advantages of defining a Jenkins pipeline in a field in source control (and in general)?

-        Single source of truth for the pipeline

-        Code review/iteration on the pipeline

-        Can be setup to automatically create a pipeline build process for all branches and pull requests

-        Audit trail for the Pipeline

3. A pipeline is a user-defined model of a CI/CD pipeline. A Pipeline’s code defines your entire build process which typically includes stages for building an application testing it and then delivering it

-        True

4. In jenkins declarative pipeline syntax, the pipeline is organized into the following:        

-        pipeline block containing stages

5.  A stage block defines a conceptually distinct subset of tasks performed by the pipeline (eg. “Build”, “Test”, and “Deploy” stages)

-        True

6. The agent section of a declarative pipeline definition has which three characteristics from the list below

-        Required

-        Specifies where the pipeline or stage will execute within the jenkins environment

-        Can specify a docker image

7. A jenkins pipeline should be triggered by which of the following. Choose the best answer.

-        Change to the source code

8. It is generally considered best practice to define and maintain the Jenkins pipeline definition directly within a Jenkins build job

-        False

9. A step in a Jenkins pipeline is a single task. Fundamentally, a step tells Jenkins what to do at a particular point in time

An example of a step would be a shell command, such as executing the make command, ie., sh ‘make’

-        True

10. Jenkins pipelines support parallel execution and definition of shared libraries (for reuse).

-        True

Quiz 5:

1. In jenkins pipeline, a shared library consists of three items (one of which is optional). What are those three items?

-        Name

-        Source Code Retrieval Methods

-        Version

2.  Shared Libraries in Jenkins pipelines let us share parts of Piplines between various projects to reduce redundancies and keep code “DRY”.

-        True

3. Shared libraries for Jenkins pipelines can include code written in which language

-        Groovy

4. Given the shared library below in the file vars/evenOrOdd.goovy in my-shared-library, how would you import ad call the code

// vars/evenOrOdd.groovy

def call(int buildNumber) {

  if (buildNumber % 2 == 0) {

    pipeline {

      agent any

      stages {

        stage('Even Stage') {

          steps {

            echo "The build number is even"

          }

        }

      }

    }

  } else {

    pipeline {

      agent any

      stages {

        stage('Odd Stage') {

          steps {

            echo "The build number is odd"

          }

        }

      }

    }

  }

}

-        @Library(‘my-shared-library’) _

evenOrOdd(currentBuild.getNumber())

5.  A shared repository is organized into the following folders:

            /src - Holds Groovy source files, typically as classes

            /vars - Holds script field that are exposed as variables in Pipelines

            /resources - Holds non-Groovy files

-        True

6. There are several tools and resources that may help with development of Jenkins Pipelines. Select the tools available from the list below (hint: there are four)

-        Blue Ocean Editor

-        Command-Line Pipeline Linter

-        IDE Plugin (for Eclipse, VisualCode, etc).

-        Replay Pipeline Runs with Modifications

7. In Lab 5 you created a Jenkinfile that defined a pipeline for a Python program. What were the stages in that pipeline

-        Build, Test, Integration Test

8. Why would we want to use shared libraries for Jenkins pipelines?

-        Code Reuse

9. Global Pipeline Libraries, defined in the Jenkins Configuration, are available to any pipeline jobs in the Jenkins server.

-        True

Midterm:

1. In which scenario below would using Cloud Based Software (ie, SaaS) likely be most advantageous?

-        You are a small company with limited IT resources

2. Define three characteristics of on-premise infrastructure from the list below

-        Pay Upfront

-        Controlled By Your Organization

-        Capital Expense

3. Why would we want to integrate Enterprise Systems? Select the best answer.

-        To improve efficiency

4.  Define three characteristics of cloud infrastructure from the list below

-        Controlled by a 3rd party

-        Pay as you go

-        Operational expense

5.  Which are examples of enterprise systems. Select all that would apply.

-        System for managing the personal information of employees and used by the Human Resources department

-        Time Tracking system that all employees use to fill out a weekly timesheet to record the hours they worked that week

-        Knowledge Base tools used by the software development teams to collaborate and share information related to designs, setup and installations of the software they are building

-        Source code management system used by multiple software development teams to store the code for their software

-        Web-based customer relationship management (CRM) system for tracking existing and potential customers by a sales team

6.  Which of the following would be considered examples of Non-Functional Requirements?

-        A web application should be capable of handling 2 million concurrent users without affecting its performance

-        A web application should work on the Chrome, Firefox and Safari browsers

7. Which of the following are examples of Functional Requirements?

-        The system should bill a user’s credit card after confirmation of an order

-        A web application should allow users to enter order and be informed when the order completes

8.  Match the capability to the tool:

-        Confluence: Knowledge base

-        GitLab: Source Code Management

-        JIRA: Work Management

-        Jenkins: Work Management

9. Match the tool to the capability

-        Trello: Work Management

-        Travis CI: Continuous Integration

-        MediaWiki (used by Wikipedia): Knowledge Base

-        GitHub: Source Code Management

10. What capabilities does Confluence provide? Select the best answer

-        Knowledge Base

11. A stakeholder is anyone who has an interest (or concern) in the realization of the system or tools you are evaluating and planning to bring into the enterprise. The interests of your stakeholders may include features, cost, deployment, operations

-        True

12.  What should go in your project’s single source code repository?

-        Source code

-        Installation scripts

-        Test scripts

-        Database schema

13.  Identify the three primary practice areas of DevOps:

-        Continuous Delivery

-        Infrastructure automation

-        Site reliability engineering

14. What are the advantages of defining a Jenkins pipeline in a file in source control?

-        Single source of truth for the pipeline

-        Audit trail for the pipeline

-        Code review/iteration on the pipeline

-        Can be set to automatically create a pipeline build process for all branches and pull requests

15. Which of the following are important characteristics of a good Continuous Integration pipeline?

-        Automated Build

-        Fast Build and Test

-        Visibility (of the status)

-        Automated Tests

-        Runs on Every Checkin to the Source Code Repository

(note this was everything except manual)

16. Three benefits of static code analysis include:

-        Ensure code complies with industry standards

-        Automated tools can reduce manual code review effort

-        It can reveal errors that do not manifest themselves until a disaster occurs weeks, months or years after release

17.  The key advantage to using a shared library in Jenkins is that it allows us to reuse all or a portion of a Jenkins pipeline definition in multiple Jenkins pipelines. This is related to the DRY principle.

-        True

Quiz 7:

1. The agents that run your jobs in GitLab CI

-        Runners

2. Made up of jobs and stages in GitLab CI

-        Pipelines

3. A way to store values you want to re-use in a GitLab CI pipeline

-        CI/CD Variables

4.  A reusable single pipeline configuration unit in GitLab CI

-        CI/CD Components

5. A GitLab runner is an agent that can run on physical machines or virtual instances. They are effectively equivalent to a Jenkins slave node

-        True

6.  A GitLab runner with a shell executor has access to all the dependencies install on the machine it is running on

-        True

7. Three types of runners based on which projects have access to them are…

-        Shared runners for use by all projects in your GitLab

-        Project runners for use by by individual projects in your GitLab

-        Group runners for use by all projects and subgroups in a group

8. Self-managed runners are hosted on your own infrastructure

-        True

9. The closest equivalent to a Jenkinsfile pipeline steps block in a gitlab-ci.yml is…

-        script

10.  The gitlab-ci.yml file in GitLab CI is analogous to the Jenkinsfile in Jenkins

Within these files the jobs in gitlab-ci.yml pipeline are equivalent to the stages in a Jenkinsfile pipeline

-        False

Quiz 8:

1. Identify two key characteristics of an artifact repository

-        Artifacts are shared

-        Artifacts are version controlled

2. What advantage does an artifact repository have over storing artifacts in plain files directly on a shared filesystem?

-        Artifacts are versioned

3. Why would you use an artifact management tool (ir Nexus, artifactory) to store binary artifacts rather than your source code management tool (ie. Git)

-        Avoid bloating your source code repositories with large files

4. In addition to sonatype Nexus, what are some other artifact management tools (discussed in the reading/video)?

-        Maven Artifact Repository

-        Artifactory

-        Archiva

5. An artifact repository can store 3rd party artifacts from the internet. What are the advantages of this (identify 3 in the list below)?

-        Reduce network bandwidth and dependency on remote repositories          

-        Insulate your company from outages in the internet, outages of public repositories (Maven Central, npm, etc.), or even removal of an open source component

-        Faster build times

6. A component is a resource like a library or framework that is used as part of your software application at runtime, integration or unit test execution time or required as part of your build or development process.

-        True

7. A component can even be an entire software application or static resource. Docker images are examples of components.

-        True

8. Examples of typical component formats for dependencies or binary artifacts include:           

-        Docker Images

-        Zip or .tar.gz Files

-        Java JAR, WAR, EAR Formats

-        RubyGem

9. To provide easy access to components, open source communities aggregate collections of components (i.e., artifacts) into 'public repositories'. Which are examples of public repositories?

-        Maven Central Repository

-        Docker Hub

10. A Repository Manager manages access to all the public repositories and components used by your development team and additionally is the target for internal software components built by your development team.

-        True

Quiz 9:

1. When we deploy software more frequently, we must accept lower levels of stability and reliability in our systems.

-        False

2. Identify three benefits of adopting Continuous Delivery practices.

-        Lower risk releases

-        Higher quality

-        Lower costs

3. There are five principles at the heart of continuous delivery:

Build quality in

Work in small batches

Computers perform repetitive tasks, people solve problems

Relentlessly pursue continuous improvement

Everyone is responsible

Match the principle with the most appropriate description below.

-        Work in small batches: It reduces the time it takes to get feedback on our work, makes it easier to triage and remediate problems, increases efficiency and motivation, and prevents us from succumbing to the sunk cost fallacy.

-        Relentlessly pursue continuous improvement: The best organizations are those where everybody treats improvement work as an essential part of their daily work, and where nobody is satisfied with the status quo.

-        Everyone is responsible: In high performing organizations, nothing is “somebody else’s problem.” Developers are responsible for the quality and stability of the software they build. Operations teams are responsible for helping developers build quality in. Everyone works together to achieve the organizational level goals, rather than optimizing for what’s best for their team or department.

-        Computers perform repetitive tasks, people solve problems: The goal is for computers to perform simple, repetitive tasks, such as regression testing, so that humans can focus on problem-solving. Thus computers and people complement each other.

-        Build quality in: Creating and evolving feedback loops to detect problems as early as possible is essential and never-ending work in continuous delivery.

4. One key goal of Continuous Delivery is to automate manual repetitive processes. In order to do that we need to version control everything required to perform these processes, including source code, test and deployment scripts, infrastructure and application configuration information, and the many libraries and packages we depend upon. This is referred to as Configuration Management.

What are two overriding goals of Configuration management?

-        Reproducibility

-        Traceability

5. The practice of continuous integration was invented to address problems such as:

Painful integration of long-lived branches into the mainline (ie main or master)

Long integration and test phases prior to a release

-        True

6. Continous testing can be best defined as…

-        Running tests continually throughout the delivery process

7. Once we have continuous integration and test automation in place, we can create a deployment pipeline. This is the key pattern in continuous delivery.

In the deployment pipeline pattern, every change runs a build that does which of the following (hint: includes both CI and CD portions of the build)? Select four from the list below.

-        Runs additional tests on packages that pass unit tests

-        Allows for self-service deployment of packages that pass all automated tests

-        Creates packages that can be deployed to any environment

-        Runs unit tests (and possibly other tests) to give developers feedback

8. In the deployment pipeline, every change is effectively a release candidate.

-        True

9.  Docker enabled the following three use cases:

-        Responsive deployment and scaling

-        Fast, consistent delivery of your applications

-        Running more workloads on the same hardware

10. Docker Compose is a tool for defying and running multi-container Docker applications. It allows you to start and stop multiple docker containers with single commands.

-        True

Quiz 10:

1. In Trunk-based development, developers and release engineers only branch when it was absolutely necessary.

-        True

2. What are three benefits of using Trunk-Based development?

-        Helps minimize merge conflicts because no branches are hanging out in development for too long

-        Encourages all changes to come back to the mainline quickly and therefore eliminates unnecessary divergence.

-        It enables developers to move fast. They do not need to deal with multiple steps before merging their code into the mainline.

3.  What two scenarios below would be best for Trunk-Based Development?

-        Experienced team that needs less oversight

-        Pushing out a new product fast

4. Feature driven development (also called feature-based development) breaks up branches based on the features in a product. Teams plan, design, and build by features.

-        True

5. What are two benefits of using Feature Branching?

-        Can more easily manage large-scale projects

-        Provides more tight control over what is being merged into the mainline, and where. This is especially important if there are lots of teams, geographically dispersed teams, outsourced teams, and/or junior developers.

6. Feature Branching is most closely associated with the following Git workflow

-        Gitflow

7. What two scenarios below would be best for Feature Branching?

-        Big team with a variety of skill levels

-        Software is mission-critical and requires good quality control

8. Pull requests let you tell others about changes you've pushed to a branch in a repository on GitLab. Once a pull request is opened, you can discuss and review the potential changes with collaborators and add follow-up commits before your changes are merged into the base branch.

-        False

9. A Merge Request (MR) is the basis of GitHub as a code collaboration and version control platform. It’s exactly as the name implies: a request to merge one branch into another.

-        False

10. How can you use a merge/pull request to improve the quality of your code? Select 3 from the list below.

-        Run a CI pipeline on your proposed changes

-        Get feedback from your collaborators/team members on your proposed changes.

-        Require team lead/manager approval before merging into the baseline branch (i.e., master).

Quiz 11:

1. UI CI/CD variables in GitLab CI are equivalent to what in Jenkins? Select the best answer.

-        Pipeline parameters

2. Three reasons to use CI/CD variables in your pipeline:

-        Store values for re-use

-        Control the behaviour of jobs in your pipeline

-        Avoid hard-coding values

3. Identify two ways you can deal with variables containing sensitive information like API keys, usernames or passwords in your GitLab CI pipeline:

-        Mask the variables so it does not show up in job logs

-        Make then a UI variable so they are specified when the pipeline is run

4. It is safe to store sensitive information in CI/CD variables since they are encrypted in your gitlab-ci.yml file

-        False

5. Pre-Defined CI/CD variables are those that you as a pipeline developer define in advance

-        False

6. Rules in GitLab CI are equivalent to which of the following in Jenkins? Select the best answer

-        When

7.  You can only use pre-defined CI/CD variables in job rules

-        False

8. A job template can be added to a gitlab-ci.yml pipeline using the includes keyword.

-        True

9. Which of the following are valid CI/CD template types in GitLab CI?

-        Pipeline template

-        Job template

10. In self hosted GitLab CI systems, enterprises often have a need to share their own CI/CD templates across teams. The GitLab system administrator can designate a project instance-wide collection of file templates.

-        True

Final Practice Quiz:

Identify two key characteristics of an artifact repository

●       Artifacts are shared

●       Artifacts are version-controlled

An enterprise development environment may be deployed either on-premise, in the cloud or both.

●       True

Three benefits of static code analysis include:

●       Automated tools can reduce manual code review efforts

●       Ensure code complies with industry standards

●       It can reveal errors that do not manifest themselves until a disaster occurs weeks, months or years after release

Match the tool to the capability in an Enterprise Development environment

●       Gitlab: Souce code management

●       Jenkins: Continuous integration/Continuous Delivery Pipelines

●       SonarQube: Static Code analysis

●       Nexus: Artifact management

●       JIRA: Work Management

●       Confluence: Knowledge base

Static code analysis is best described as…

●       Inspection of code without execution

The following is a practical definition of DevOps:

DevOps is the practice of operations and development engineers participating together in the entire service lifecycle, from design through the development process to production support.

●       True

Infrastructure Automation refers to creating your systems, OS configs, and app deployments as code. This code is stored in a source code management system.

●       True

Identify three benefits of adopting Continuous Delivery practices.

●       Low risk releases

●       Higher quality

●       Lower costs

Frequently committing to the mainline in the source code repository helps developers quickly find out if there’s a conflict (code/merge conflict) between two developers.

●       True

A continuous integration server is where (select the best answer):

●       The build is run automatically every time the code changes

You have been tasked with assessing source code management tools for software development at the company you work for. What features from the following list would be more important from a management perspective (i.e., the project or team manager)?

●       Price

●       Ability to review commit history to measure developer performance for year-end reviews

You have been tasked with assessing source code management tools for a software development at the company you work for. What features from the following list would be most important from a developer perspective (i.e., the end user)?

●       Easy to use user interface for browsing repositories

●       Ability to integration with common IDEs

●       Ability to review commit history to track down bugs

Which of the following are categories of Non-Functional Requirements?

●       Availability

●       Usability

●       Maintainability

●       Scalability

●       Security

●       Testability

You have been tasked with assessing source code management tools for a software development at the company you work for. What features from the following list would be most important from a operational perspective (i.e., the person that installs and maintains the tool)?

●       Easy of installation and maintenance

●       Ability to contact support for troubleshoot operational issues (i.e., when the server goes down)

Select the best definition of a Non-Functional Requirement

●       Defines constraints on the design more implementation of a system or its component

There are several tools and resources that may help with development of Jenkins Pipelines. Select the tools available from the list below.

●       IDE Plugin (for Eclipse, VisualCode, etc).

●       Replay pipeline runs with modifications

●       Command-line pipeline linter

●       Blue ocean editor

What are the advantages of defining a Jenkins pipeline in a file in source control?

●       Single source of truth for the pipeline

●       Can be setup to automatically create a pipeline build process for all branches and pull requests

●       Audit trail for the pipeline

●       Code review/iteration on the pipeline

In Jenkins declarative pipeline syntax, the pipeline is organized into the following:

●       Pipeline block containing stages

Why would we want to use shared libraries for Jenkins pipelines?

●       Code reuse

The definition of a Jenkins pipeline is written in a text file. What is this text file called?

●       Jenkinsfile