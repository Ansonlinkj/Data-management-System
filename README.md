# Data Management System
## <A short Introduction>
The whole data management system is made up of two end-user applications (User Application & Administrator Application)


User Application: Users are allowed to view information in a user-friendly format by typing keywords or selecting the option to search.
Administrator Application: Data manager are allowed to modify, add and delete the information in the database.

Database we used in mysql server: "mads"





## <Compile the c file >

Command:

User Application:gcc -o userapp userapp.c `mysql_config --cflags --libs`

Administrator Application: gcc -o adminapp adminapp.c `mysql_config --cflags --libs`




## <Instruction with example>
Run the User Application:

	1.In the directory "database" run the command below:

	"./userapp"
	
	2.Now you are in the User Application.
	
	3.Type in the number based on the menu option.
		
		option<1~2>:-Show Top 10 Best Oscar Nominated Movies(2016~2018)
 			      -The Studio that produced the most Oscar Movies(2016~2018)

		option<3>:  -Winners and Nominations of each Oscar reward(2016~2018)

				1. An inner menu showing each Oscar Reward)
			
				2. Type in the number based on the menu option (EX "1 best_actor")

				3. Type in the keywords for searching  (EX "Name:Ryan 
				                                            Role:Sebastian 
				                                            Movie:la"   )
				4.Get the result

		option<4>:  -Use keyword to search Movies, Studios, Actors or Directors
				
				
				1. An inner menu showing Movies, Studios, Actors and Directors
  
				2. Type in the number based on the menu option (EX "1 Movies")

				3. Type in the keywords for searching  (EX "theeb")
 
				4. Get the result

		option<5>: -Quit the Application

Run the Administrator Application:
	
	1. In the directory "database" run the command below:

	"./adminapp"

	2. Now you are in the Administrator Application.


	3.Type in the number based on the menu option.
				
		option<1>: -Add Data
				
		            1. A inner menu showing each available table

		            2. Type in the table's name to choose table (EX "actors")
			
	 	            3. A menu of attributes of the chosen table with numbers that represent each attribute will be shown 
				
				  EX in "actors" case, attributes will be 
          				"""""""""""""""""
						1 name
						2 DOB
						3 birthplace
						4 wiki_page
          				"""""""""""""""""				


		      
		            3. Type in values according to the number that represents the attributes to insert new data row 
				  (Caution:enclose each value with single quote '', unless the value is in integer data format )
				
				  EX 1 'Martin Lin'
				     2 '1992-12-21'
				     3 'Newark'
				     4 'www.google.com'


		option<2>: -Delete Data
				

		            1. A inner menu showing each available table

		            2. Type in the table's name to choose table (EX "actors")

		            3. Type in the condition of the data row you want to delete 	      Format:(attribute_name='VALUE')
			        (Caution:enclose each value with single quote '', unless the value is in integer data format ) 
		              (EX birthplace='Newark')

		            
		option<3>: -Modify Data
		 
		            1. A inner menu showing each available table
		         
		            2. Type in the table's name to choose table (EX "actors")
		
		            3. Type in new value of the attribute that you want to modify 		Format:(attribute_name='NEW_VALUE')
		               (Caution:enclose each value with single quote '', unless the value is in integer data format ) 
		               (EX DOB='1997-7-18')

		            4. Type in the condition of the data row you want to modify          Format:(attribute_name='VALUE')
		               (Caution:enclose each value with single quote '', unless the value is in integer data format ) 
		               (EX name='Fionn Whitehead')
