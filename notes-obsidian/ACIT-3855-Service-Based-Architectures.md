# Week 1
- #outline 
  - | Type | % | Desc. |
    | --- | --- | --- |
    | Quizzes | 20% | There will be an in-class quiz at the beginning of each class (except the first and last), including a midterm review quiz. Based on pre-reading materials posted to the Learning Hub. | 
    | Project Labs | 35% | A microservices based application will be incrementally built and deployed through the project labs. - Labs are done individually, typically require a demo and are due by the end of the next class |
    | Assignments | 10% | There are two assignments – one written and one coding. |
    | Final Exam | 35% | Concepts and Coding. |
    - Quizzes will only be done in-class only. There are no late or make-up quizzes, but the lowest quiz of the term will be dropped. There is a 20% penalty per week for late lab submissions, up to a maximum of 2 weeks.
	- Passing Criteria:  
		- Students must complete a minimum of 80% of the Project Labs.  
		- Students must achieve a minimum of 50% on the combination of the Quizzes and Final Exam (i.e., 27.5/55).  
		- Students must achieve an overall grade of at least 50% in the course.  
 ## Service #service
- A service is a discrete unit of functionality that can be accessed remotely and can be acted upon and updated independently. This is very much like our definition of a class but with RESTful API!
- A service typically has four properties:
	- It logically represents a business activity with a specific outcome (i.e., single responsibility) 
	- It is self-contained 
	- It is a “black-box” for its consumers 
	- It may use other underlying services
## Service Oriented Architecture (SOA) #soa
- Style of software design where the software components are Services that interact through a communication protocol over a network.

# Week 2 
## Microservices #microservices Concepts High level definition of an MSA (Microservices Architecture 
> In short, the microservice architectural style is an approach to developing a single application as a *suite of small services*, each *running in its own process and communicating with lightweight mechanisms, often an HTTP resource API. These services are *built around business capabilities and *independently deployable* by fully automated deployment machinery. There is a *bare minimum of centralized management**** of these services, which may be written in different programming languages and use different data storage technologies. — James Lewis and Martin Fowler (2014)  
 ## Benefits and Costs of an MSA 
### Benefits of MSA: 
 Strong Module Boundaries: Microservices reinforce modular structure, which is particularly important for larger teams. - Independent Deployment: Simple services are easier to deploy, and since they are autonomous, are less likely to cause system failures when they go wrong. - Technology Diversity: With microservices you can mix multiple languages, development frameworks and data-storage technologies. 
 ### Costs of MSA
 Distribution: Distributed systems are harder to program, since remote calls are slow and are always at risk of failure. - Eventual Consistency: Maintaining strong consistency is extremely difficult for a distributed system, which means everyone has to manage eventual consistency. - Operational Complexity: You need a mature operations team to manage lots of services, which are being redeployed regularly. 
 ## Characteristics of a Microservice Architecture 
1. **Componentization via Services**: Microservices are treated as independent components which communicate through well-defined mechanisms like web service requests, allowing for easy replacement and upgrade.
2. **Organized around Business Capabilities**: Microservices are structured around specific business capabilities, with each service encompassing a broad range of functionalities, including user-interface, persistent storage, and external collaborations. 
3. **Products not Projects**: Microservices are managed as products with ongoing development and support, rather than as projects with a definite end. 
4. **Smart Endpoints and Dumb Pipes**: Communication in microservices emphasizes simplicity, with intelligent processing at the endpoints and minimal logic in the communication paths. 
5. **Decentralized Governance and Data Management**: Microservices promote decentralized decision-making in both technology choices and data management, allowing each service to choose the best tools and data storage for its needs. 
6. **Infrastructure Automation**: Emphasizes automated deployment and management of services to support continuous delivery and efficient scaling. 
7. **Design for Failure**: Microservices are designed to handle the failure of individual components gracefully, ensuring overall system resilience.
8. **Evolutionary Design**: Microservices support and encourage evolutionary changes in the system, with services being independently replaceable and upgradeable.
![[Pasted image 20240129161838.png]]
![[Pasted image 20240129161946.png]]