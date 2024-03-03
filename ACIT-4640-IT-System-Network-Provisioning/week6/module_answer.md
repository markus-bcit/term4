## module exercise

Unzip the zip file in the exercise starter files below and use it to answer the following questions.

1. How is data passed into a module?
	- It depends on what is being. Things like outputs and variables are automatically to vars if in a variables.tf file. Module files are passed in by using module 'name' {params} where the params source the directory 
1. How is data passed out of a module?
	- Using the output {value=value}. These outputs can then be referenced in the parent configuration.
1. Modify the `mod_demo` module to create a security group module for use in the mod_demo project?