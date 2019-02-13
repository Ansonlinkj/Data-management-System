
/*To run the C code, use the command:




Documentation for the C API can be found at

https://dev.mysql.com/doc/refman/5.5/en/c-api.html
*/

#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <mysql/my_config.h>
#include <mysql/mysqld_error.h>



int main(void) {
    MYSQL mysql, *sock;
    MYSQL_RES *res;
    MYSQL_ROW row;
    
    char *db = "mads";
    char *usr = "ansonlin";
    char *pwd = "702442000";

    char qbuffer[800];
    int option;


    //function1
    int clean_stdin()//check the character in the input
    {
       while(getchar()!='\n')
      {

       continue;

      }

    }

    //function2
    int invalid_msg()//print the invalid option
    {
       printf("Invalid Option! Please Try again!\n");
       
    }


    //function3   
    int connectmysql()//connect to mysql server
    {
       if(mysql_query(sock, qbuffer)) {
        fprintf(stderr, "Query failed (%s)\n",mysql_error(sock));
        exit(1);
    }
      if(!(res = mysql_store_result(sock))) {
        fprintf(stderr,"Couldn't get result from %s\n",mysql_error(sock));
        exit(1);
    }
   
    }


    //function4
    //conncect the mysql server
    mysql_init(&mysql);
    if (!(sock = mysql_real_connect(&mysql,"localhost",usr,pwd,db,0,NULL,0))) {
        fprintf(stderr,"Couldn't connect to engine!\n%s\n\n",mysql_error(&mysql));
        perror("");
        exit(1);
    }
    mysql.reconnect = 1;



    //into application
   
    
          ///while(1)
	///{
       /*	   printf("\nChoose Your Mode:\n 1.User Mode \n 2.Adminstrator Mode\n");
    	   scanf("%d",&option);
           clean_stdin();
           switch (option)
                {
                  case 1://user mode
                    {*/
                          //connect to database
                     sprintf(qbuffer,"use %s", db);
                     
                     printf("\n");

                     if(mysql_query(sock, qbuffer)) 
                          {
                           fprintf(stderr, "Query failed (%s)\n",mysql_error(sock));
                           exit(1);
                           }

                     printf("Welcome to User Mode\n");      

			
                 
		  while(1){//User Menu
   
                     int user_option;
		     
	             printf("\nWhat do you want to search?\n Fun Facts: \n 1.Show Top 10 Best Oscar Nominated Movies(2016~2018)\n 2.The Studio that produced the most Oscar Movies(2016~2018)\n \n General Info:\n 3.Winners and Nominations of each Oscar reward(2016~2018)\n 4.Use keyword to search Movies, Studios, Actors or Directors\n 5.Exit User Application\n");
	             scanf("%d",&user_option);
                     clean_stdin();
  		     switch(user_option){
                       case 1:// Top 10 Movies
                       {
                          printf("Top 10 Oscar Movies through the Years(2016~2018)\n");
 		          sprintf(qbuffer,"select Rank, title, rating from (select (select count(distinct rating) from movies where rating >=m.rating) Rank, title, rating from movies m Order by rating desc) mainrank where Rank Between 1 and 10;");
                          

			  
                        connectmysql();
    			while(row = mysql_fetch_row(res))
                       {
        		printf("%s %s %s\n",row[0],row[1],row[2]);
    			}
			



                        mysql_free_result(res);
			
                        continue;                       
         
      
                        }          
                       case 2:// Which Studio Produce the most Oscar Nominated Movies
                       {
                         
			 sprintf(qbuffer,"select studio_name, count(title) as total_movies from movies group by studio_name order by total_movies DESC limit 1;");
                         connectmysql();
		        printf ("Most oscar nomination produced goes to......\n");
			while (row = mysql_fetch_row(res))
                       {
                        printf("Studio:<%s>\nTotal Movies:<%s>\n",row[0],row[1]);
                        }
			
                     	mysql_free_result(res);

                        continue;
                       }




		       case 3://Winners of Oscar
		       { 

                       

		while(1){ 
                        
                        sprintf(qbuffer,"select * from (Select distinct TABLE_NAME from INFORMATION_SCHEMA.COLUMNS where COLUMN_NAME IN ('win_or_nominate') and TABLE_SCHEMA='mads') as Oscars;");
                        connectmysql();
                        printf("We have information of awards below\n");
                        int index=1;
                        while(row =mysql_fetch_row(res))
                         {
                          printf("%d %s\n",index,row[0]);
                          index=index+1;
                         }
                         mysql_free_result(res);
                         
                         int user_option2;
                         printf("Choose the option:(<0+ENTER> to previous menu)\n");
			 scanf("%d",&user_option2);
			 clean_stdin();			 
                         switch(user_option2)
			{      
				 case 0://exit
				{
				break;


				}
        		       			

				case 1://best_actor
				{
				 
				 char name[30];
				 char role[30];
				 char movie[30];
				 printf("Searching Oscar Best Actor by Name...Role....Movie\n");
				 printf("Name:");
				 scanf("%s",name);
				 printf("Role:");
				 scanf("%s",role);
				 printf("Movie:");
				 scanf("%s",movie);
                                 clean_stdin();
				 sprintf(qbuffer,"select best_actor.name, best_actor.role, best_actor.movie, best_actor.year, best_actor.win_or_nominate from best_actor left join actors on best_actor.name=actors.name ");
				 strcat(qbuffer,"where (best_actor.name like '%%");
				 strcat(qbuffer,name);
				 strcat(qbuffer,"%%'");
				 strcat(qbuffer," or best_actor.role like'%%");
				 strcat(qbuffer,role);
				 strcat(qbuffer,"%%'");
				 strcat(qbuffer," or best_actor.movie like'%%");
				 strcat(qbuffer,movie);
				 strcat(qbuffer,"%%');");
				 
                                 connectmysql();
				 int index=1;
				 printf("\nResults:\n");
							
				 

 
                                 while(row=mysql_fetch_row(res))
					
					{
					  
                                          printf("%d: Name: <%s>\nRole: <%s>\nMovie: <%s>\nYear: <%s>\nWinner or just Nomination: %s\n\n",index,row[0],row[1],row[2],row[3],row[4]);
					  index=index+1;
				        }
				  

                                 mysql_free_result(res);
                                 continue;
					



                                 }


				        
                                
                                case 2://best_actress
 				{
                                 char name[30];
                                 char role[30];
                                 char movie[30];
                                 printf("Searching Oscar Best Actress by name...role....Movie\n");
                                 printf("Name:");
                                 scanf("%s",name);
                                 printf("Role:");
                                 scanf("%s",role);
                                 printf("Movie:");
                                 scanf("%s",movie);
                                 clean_stdin();
                                 sprintf(qbuffer,"select best_actress.name, best_actress.role, best_actress.movie, best_actress.year, best_actress.win_or_nominate from best_actress left join actors on best_actress.name=actors.name ");
                                 strcat(qbuffer,"where (best_actress.name like '%%");
                                 strcat(qbuffer,name);
                                 strcat(qbuffer,"%%'");
                                 strcat(qbuffer," or best_actress.role like'%%");
                                 strcat(qbuffer,role);
                                 strcat(qbuffer,"%%'");
                                 strcat(qbuffer," or best_actress.movie like'%%");
                                 strcat(qbuffer,movie);
                                 strcat(qbuffer,"%%');");
                                 
                                 connectmysql();
                                 int index=1;
                                 printf("\nResults:\n");                                
				 while(row=mysql_fetch_row(res))

                                        {

                                          printf("%d: Name: <%s>\nRole: <%s>\nMovie: <%s>\nYear: <%s>\nWinner or just Nomination: %s\n\n",index,row[0],row[1],row[2],row[3],row[4]);
                                          index=index+1;
                                        }


                                 mysql_free_result(res);
   				 continue;
                                  
				}







 				case 3:/*best_foreign_language*/
                                {
				
				 char title[40];
                                 char language[40];
                                 char type[40];
                                 printf("Searching Oscar Best Foreign Language Movie by Movie...language....type of movie\n");
                                 printf("Movie:");
                                 scanf("%s",title);
                                 printf("Language(ex:Spanish,danish,Russia,Turkish,Swedish....):");
                                 scanf("%s",language);
                                 printf("Type(ex:comedy,drama,action..):");
                                 scanf("%s",type);
                                 clean_stdin();
                                 sprintf(qbuffer,"select best_foreign_language.title, best_foreign_language.language, best_foreign_language.type, best_foreign_language.year, best_foreign_language.win_or_nominate from best_foreign_language left join movies on best_foreign_language.title=movies.title");
                                 strcat(qbuffer," where (best_foreign_language.title like '%%");
                                 strcat(qbuffer,title);
                                 strcat(qbuffer,"%%'");
                                 strcat(qbuffer," or best_foreign_language.language like'%%");
                                 strcat(qbuffer,language);
                                 strcat(qbuffer,"%%'");
                                 strcat(qbuffer," or best_foreign_language.type like'%%");
                                 strcat(qbuffer,type);
                                 strcat(qbuffer,"%%');");
                                 printf(qbuffer);
                                 connectmysql();
                                 int index=1;
                                 printf("\nResults:\n");

			         while(row=mysql_fetch_row(res))

                                        {

                                          printf("%d: Name: <%s>\nLanguage: <%s>\nType: <%s>\nYear: <%s>\nWinner or just Nomination: %s\n\n",index,row[0],row[1],row[2],row[3],row[4]);
                                          index=index+1;
                                        }


                                 mysql_free_result(res);
                                 continue;

                                 
                                }













                                case 4://best_original_screenplay
                                {
                                 char title[40];
                                 char screenwriter[40];
                                 char type[40];
                                 printf("Searching Oscar Best original screenplay by Movie...screenwriter....type of movie\n");
                                 printf("Movie:");
                                 scanf("%s",title);
                                 printf("screenwriter:");
                                 scanf("%s",screenwriter);
                                 printf("Type(ex:comedy,mystery,animation..):");
                                 scanf("%s",type);
                                 clean_stdin();                                 
                                 sprintf(qbuffer,"select best_original_screenplay.title, best_original_screenplay.screen_writer, best_original_screenplay.type, best_original_screenplay.year, best_original_screenplay.win_or_nominate from best_original_screenplay left join movies on best_original_screenplay.title=movies.title");
                                 strcat(qbuffer," where (best_original_screenplay.title like '%%");
                                 strcat(qbuffer,title);
                                 strcat(qbuffer,"%%'");
                                 strcat(qbuffer," or best_original_screenplay.screen_writer like'%%");
                                 strcat(qbuffer,screenwriter);
                                 strcat(qbuffer,"%%'");
                                 strcat(qbuffer," or best_original_screenplay.type like'%%");
                                 strcat(qbuffer,type);
                                 strcat(qbuffer,"%%');");
                                 printf(qbuffer);
                                 connectmysql();
                                 int index=1;
                                 printf("\nResults:\n");
                                  while(row=mysql_fetch_row(res))

                                        {

                                          printf("%d: Movie: <%s>\nScreenwriter: <%s>\nType: <%s>\nYear: <%s>\nWinner or just Nomination: %s\n\n",index,row[0],row[1],row[2],row[3],row[4]);
                                          index=index+1;
                                        }

                                 mysql_free_result(res);



                                 continue;
                                }



                                /////////////////////
                                case 5://best_picture
				{
                                 char title[40];
                                 char producer[40];
                                 char type[40];
                                 printf("Searching Oscar Best Picture by Movie...Producer....type of movie\n");
                                 printf("Movie:");
                                 scanf("%s",title);
                                 printf("Producer:");
                                 scanf("%s",producer);
                                 printf("Type(ex:science fiction,drama,action..):");
                                 scanf("%s",type);
                                 clean_stdin();
                                 sprintf(qbuffer,"select best_picture.title, best_picture.producer, best_picture.type, best_picture.year, best_picture.win_or_nominate from best_picture left join movies on best_picture.title=movies.title");
                                 strcat(qbuffer," where (best_picture.title like '%%");
                                 strcat(qbuffer,title);
                                 strcat(qbuffer,"%%'");
                                 strcat(qbuffer," or best_picture.producer like'%%");
                                 strcat(qbuffer,producer);
                                 strcat(qbuffer,"%%'");
                                 strcat(qbuffer," or best_picture.type like'%%");
                                 strcat(qbuffer,type);
                                 strcat(qbuffer,"%%');");
                                 printf(qbuffer);
                                 connectmysql();
                                 int index=1;
                                 printf("\nResults:\n");  
				 while(row=mysql_fetch_row(res))

                                        {

                                          printf("%d: Movie: <%s>\nProducer: <%s>\nType: <%s>\nYear: <%s>\nWinner or just Nomination: %s\n\n",index,row[0],row[1],row[2],row[3],row[4]);
                                          index=index+1;
                                        }

                                 mysql_free_result(res);


				continue;

  				}
				/////////////////////






                                /////////////////////
                                case 6://best_sup_actor
				{
                                 char name[30];
                                 char role[30];
                                 char movie[30];
                                 printf("Searching Oscar Best Supporting Actor by name...role....Movie\n");
                                 printf("Name:");
                                 scanf("%s",name);
                                 printf("Role:");
                                 scanf("%s",role);
                                 printf("Movie:");
                                 scanf("%s",movie);
                                 clean_stdin();
                                 sprintf(qbuffer,"select best_sup_actor.name, best_sup_actor.role, best_sup_actor.movie, best_sup_actor.year, best_sup_actor.win_or_nominate from best_sup_actor left join actors on best_sup_actor.name=actors.name ");
                                 strcat(qbuffer,"where (best_sup_actor.name like '%%");
                                 strcat(qbuffer,name);
                                 strcat(qbuffer,"%%'");
                                 strcat(qbuffer," or best_sup_actor.role like'%%");
                                 strcat(qbuffer,role);
                                 strcat(qbuffer,"%%'");
                                 strcat(qbuffer," or best_sup_actor.movie like'%%");
                                 strcat(qbuffer,movie);
                                 strcat(qbuffer,"%%');");
                                 
                                 connectmysql();
                                 int index=1;
                                 printf("\nResults:\n");

                                 while(row=mysql_fetch_row(res))

                                        {

                                          printf("%d: Name: <%s>\nRole: <%s>\nMovie: <%s>\nYear: <%s>\nWinner or just Nomination: %s\n\n",index,row[0],row[1],row[2],row[3],row[4]);
                                          index=index+1;
                                        }
				mysql_free_result(res);

 	                         continue;
                                }



                                /////////////////////
                                case 7://best_sup_actress
				{
                                 char name[30];
                                 char role[30];
                                 char movie[30];
                                 printf("Searching Oscar Best Supporting Actress by name...role....Movie\n");
                                 printf("Name:");
                                 scanf("%s",name);
                                 printf("Role:");
                                 scanf("%s",role);
                                 printf("Movie:");
                                 scanf("%s",movie);
                                 clean_stdin();
                                 sprintf(qbuffer,"select best_sup_actress.name, best_sup_actress.role, best_sup_actress.movie, best_sup_actress.year, best_sup_actress.win_or_nominate from best_sup_actress left join actors on best_sup_actress.name=actors.name ");
                                 strcat(qbuffer,"where (best_sup_actress.name like '%%");
                                 strcat(qbuffer,name);
                                 strcat(qbuffer,"%%'");
                                 strcat(qbuffer," or best_sup_actress.role like'%%");
                                 strcat(qbuffer,role);
                                 strcat(qbuffer,"%%'");
                                 strcat(qbuffer," or best_sup_actress.movie like'%%");
                                 strcat(qbuffer,movie);
                                 strcat(qbuffer,"%%');");
                                 
                                 connectmysql();
                                 int index=1;
                                 printf("\nResults:\n");
                                 while(row=mysql_fetch_row(res))

                                        {

                                          printf("%d: Name: <%s>\nRole: <%s>\nMovie: <%s>\nYear: <%s>\nWinner or just Nomination: %s\n\n",index,row[0],row[1],row[2],row[3],row[4]);
                                          index=index+1;
                                        }
				mysql_free_result(res);

                                 continue;

				}
                                           
   				
				  
                                default:
                              {
                                invalid_msg();
                                continue;
                              }
			     
	                 }
			break;
                      }
                        continue;
                    }         
			
			case 4:////Use keyword to search Movie, actor, studio, director
			{
			 
			 while(1)
				{
				int user_option3;
                         	printf("\nWhat do you want to search?\n");
                         	printf("1.Movie\n2.Actor/Actress\n3.Studio\n4.Director\n0.Quit\n");
                         	scanf("%d",&user_option3);
                         	clean_stdin();	
				switch(user_option3)
					{
					case 0://exit
					{
					break;


					
					}
					case 1://Movie
					{
					char key[200];
					printf("Type in the Keyword:\n");	
					scanf("%s",key);
					clean_stdin();
					sprintf(qbuffer,"select title, studio_name, director_name,description from movies where title like '%%");
					strcat(qbuffer,key);
					strcat(qbuffer,"%%';");
					connectmysql();
                                        int index=1;
                                        printf("\nResults:\n");
                                        while(row=mysql_fetch_row(res))
					{
					 printf("\n%d  Movie Title <%s>\n   Produced By <%s>\n   Directed By <%s>\n   Description:<%s>\n",index,row[0],row[1],row[2],row[3]);
					index=index+1;
					}
					mysql_free_result(res);
					continue;




					}
					case 2://Actor/Actress
				       {
					char key[200];
                                        printf("Type in the Keyword:\n");
                                        scanf("%s",key);
                                        clean_stdin();
                                        sprintf(qbuffer,"select name, DOB, birthplace,wiki_page from actors where name like '%%");
                                        strcat(qbuffer,key);
                                        strcat(qbuffer,"%%';");
                                        connectmysql();
                                        int index=1;
                                        printf("\nResults:\n");
                                        while(row=mysql_fetch_row(res))
                                        {
                                         printf("\n%d  Name <%s>\n   Date of Birth <%s>\n   Born in <%s>\n   More info:<%s>\n",index,row[0],row[1],row[2],row[3]);
                                        index=index+1;
                                        }
                                        mysql_free_result(res);
                                        continue;

                                          }




                                              
					case 3:///studio
					{
					char key[200];
                                        printf("Type in the Keyword:\n");
                                        scanf("%s",key);
                                        clean_stdin();
                                        sprintf(qbuffer,"select name, location, CEO, wiki_page from studio where name like '%%");
                                        strcat(qbuffer,key);
                                        strcat(qbuffer,"%%';");
                                        connectmysql();
                                        int index=1;
                                        printf("\nResults:\n");
                                        while(row=mysql_fetch_row(res))
                                        {
                                         printf("\n%d  Studio <%s>\n   Location <%s>\n   CEO <%s>\n   More info:<%s>\n",index,row[0],row[1],row[2],row[3]);
                                        index=index+1;
                                        }
                                        mysql_free_result(res);
                                        continue;
						
                                           }







             			        case 4:///Director
					{
                                        char key[200];
                                        printf("Type in the Keyword:\n");
                                        scanf("%s",key);
                                        clean_stdin();
                                        sprintf(qbuffer,"select name, DOB, highest_rate, birthplace, wiki_page from directors where name like '%%");
                                        strcat(qbuffer,key);
                                        strcat(qbuffer,"%%';");
                                        connectmysql();
                                        int index=1;
                                        printf("\nResults:\n");
                                        while(row=mysql_fetch_row(res))
                                        {
                                         printf("\n%d  Name <%s>\n   Date of Birth <%s>\n   Best directed movie <%s>\n   Born in <%s>\n   More info:<%s>\n",index,row[0],row[1],row[2],row[3],row[4]);
                                        index=index+1;
                                        }
                                        mysql_free_result(res);
                                        continue;




					}				
				


					default:{
						invalid_msg();
                        			continue;
						}



					

					}

                                       break;






				}
                         continue;
			}

                       case 5:///exit
			{
                     	  printf("GoodBye\n");
			  
			  exit(1);

			}
			
				
                        


        	       default://invalid option
        	       {
        		invalid_msg();
                        continue;
                       }
 		       
                      }
       			

           ///      }
                 




    	/*	  case 2://administrator mode
                   { 
         	    printf("Welcome to Adminstrator Mode\n");
		    exit(1);
                   } 

		  




  
                  default:
                   {
                    invalid_msg();
 		    continue;
                   }	*/
         ///}
    
///}









/*

    sprintf(qbuffer,"show databases");
    printf(qbuffer);
    printf("\n");
    if(mysql_query(sock, qbuffer)) {
        fprintf(stderr, "Query failed (%s)\n",mysql_error(sock));
        exit(1);
    }
    if(!(res = mysql_store_result(sock))) {
        fprintf(stderr,"Couldn't get result from %s\n",mysql_error(sock));
        exit(1);
    }
    while (row = mysql_fetch_row(res)) {
        printf("Database: %s\n",row[0]);
    }
    mysql_free_result(res);

    sprintf(qbuffer,"use %s", db);
    printf(qbuffer);
    printf("\n");
    if(mysql_query(sock, qbuffer)) {
        fprintf(stderr, "Query failed (%s)\n",mysql_error(sock));
        exit(1);
    }

    sprintf(qbuffer,"create table test (a int, b char(5))");
    printf(qbuffer);
    printf("\n");
    if(mysql_query(sock, qbuffer)) {
        fprintf(stderr, "Query failed (%s)\n",mysql_error(sock));
        printf("Note from TA: Make sure your real programs can elegantly handle cases like this\n");
	//exit(1);
    }

    sprintf(qbuffer,"show tables");
    printf(qbuffer);
    printf("\n");
    if(mysql_query(sock, qbuffer)) {
        fprintf(stderr, "Query failed (%s)\n",mysql_error(sock));
        exit(1);
    }
    if(!(res = mysql_store_result(sock))) {
        fprintf(stderr,"Couldn't get result from %s\n",mysql_error(sock));
        exit(1);
    }
    while (row = mysql_fetch_row(res)) {
        printf("Table: %s\n",row[0]);
    }
    mysql_free_result(res);

    mysql_close(sock);
    exit(0);*/
}
}
