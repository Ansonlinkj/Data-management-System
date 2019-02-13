
///Adminstrator Mode
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


int invalid_msg()//print the invalid option
    {
       printf("Invalid Option! Please Try again!\n");

    }


    //function3   
int connectmysql()//connect to mysql server
    {
       if(mysql_query(sock, qbuffer)) {
        fprintf(stderr, "Query failed (%s)\n",mysql_error(sock));
        
    }
      if(!(res = mysql_store_result(sock))) {
        ///fprintf(stderr,"Couldn't get result from %s\n",mysql_error(sock));
        printf("Query processed\n");
	
   	exit(1); 
}
    }

mysql_init(&mysql);
    if (!(sock = mysql_real_connect(&mysql,"localhost",usr,pwd,db,0,NULL,0))) {
        fprintf(stderr,"Couldn't connect to engine!\n%s\n\n",mysql_error(&mysql));
        perror("");
        exit(1);
    }
mysql.reconnect = 1;




sprintf(qbuffer,"use %s", db);
printf("\n");
if(mysql_query(sock, qbuffer))
    {
       fprintf(stderr, "Query failed (%s)\n",mysql_error(sock));
       exit(1);
                           }

       printf("Welcome to Adminstrator Mode\n");

while(1)
    {	
      int admin_option;
      printf("\n1.Add Data\n2.Delete Data\n3.Modify Data\n0.Exit the application\n");
      scanf("%d",&admin_option);
      clean_stdin();
      switch(admin_option)
	{   
	   case 0://exit application
		{
			printf("Goodbye\n");
			exit(1);

		}





           case 1://add data
		{
			
			sprintf(qbuffer, "show tables;");
			connectmysql();
			printf ("Tables:\n");
		       
                        while (row = mysql_fetch_row(res))
                       {
			
                        printf("%s\n",row[0]);
			
                        }
                        mysql_free_result(res);


			char table_name[50];
                        printf("\nType in the exact table name that you want to add data in\n");
			scanf("%s",table_name);
			sprintf(qbuffer, "Select COLUMN_NAME From INFORMATION_SCHEMA.COLUMNS where TABLE_NAME='");
			strcat(qbuffer,table_name);
			strcat(qbuffer,"'and TABLE_SCHEMA='mads';");
			if(mysql_query(sock, qbuffer)) {
			        fprintf(stderr, "Query failed (%s)\n",mysql_error(sock));
				continue;
    			}
      			if(!(res = mysql_store_result(sock))) {
        ///fprintf(stderr,"Couldn't get result from %s\n",mysql_error(sock));
        		printf("Query processed\n");

        		continue;
			}

			printf("%s has attributes below:\n",table_name);
			int counts=0;
			int index=1;
			char columns[50][50];
			const char *col[50];
			 while (row = mysql_fetch_row(res))
                       {
		
                        printf("%d %s\n",index,row[0]);
			col[index]=row[0];
                         
			counts=counts+1;
			index=index+1;
                        }
                        
                        mysql_free_result(res);
                         
			printf("\nInsert %d values for each column of the new data row\n",counts);
			printf("!!!Note:Add single quote for the value (Except that the value is integer)\n");
			int i;
			char strings[400][400];
			
			for (i=1;i<counts+2;i=i+1)
				{
                                                               	
					
						        
					char *name = malloc(128);
					printf("%d ",i-1);
	                   		fgets(name,128,stdin);
				        strcpy(strings[i],name);
					free(name);
					
				}
			
			sprintf(qbuffer, "Insert into ");
		
			strcat(qbuffer,table_name);
			
			///strcat(qbuffer," (");
			
			/*for (i=1;i<index+1;i=i+1)
			{
                                printf("work\n");
			  	if(i==index)
				{
					strcat(qbuffer,col[i]);
					break;
				
				}
				printf("work\n");
				strcat(qbuffer,col[i]);
				strcat(qbuffer,",");

			}
			*/
			///strcat(qbuffer,")");


                        
			strcat(qbuffer," Values (");
			for (i=2;i<counts+2;i=i+1)
				{
				 
				  if (i==counts+1)
					{
					strcat(qbuffer,strings[i]);
					break;
					}
				printf(strings[i]);
				strcat(qbuffer,strings[i]);
				strcat(qbuffer,",");
				
				}

			strcat(qbuffer,");");
		        if(mysql_query(sock, qbuffer)) {
			        fprintf(stderr, "Query failed (%s)\n",mysql_error(sock));
				continue;
   				 }		
      			if(!(res = mysql_store_result(sock))) {
        ///fprintf(stderr,"Couldn't get result from %s\n",mysql_error(sock));
        			printf("Query processed\n");

        			continue;
			}

                        /*if(mysql_query(sock, qbuffer))
			 {
        		fprintf(stderr, "Query failed (%s)\n",mysql_error(sock));
		        exit(1);
    			}
*/
			 while (row = mysql_fetch_row(res))
                       {

                        printf("%s\n",row[0]);
                        
                        
                        }

                        mysql_free_result(res);
			                        
			
			continue;


		}


 
	   case 2://delete data
		{
		        sprintf(qbuffer, "show tables;");
                        connectmysql();
                        printf ("Tables:\n");

                        while (row = mysql_fetch_row(res))
                       {

                        printf("%s\n",row[0]);

                        }
			mysql_free_result(res);
                        int i;
			char table_name[50];
			char condition[100][100];
			char *name = malloc(128);
                        printf("\nType in the exact table name that you want to delete data in\n");
                        scanf("%s",table_name);
                        sprintf(qbuffer, "Select COLUMN_NAME From INFORMATION_SCHEMA.COLUMNS where TABLE_NAME='");
                        strcat(qbuffer,table_name);
                        strcat(qbuffer,"'and TABLE_SCHEMA='mads';");
                        if(mysql_query(sock, qbuffer)) {
			        fprintf(stderr, "Query failed (%s)\n",mysql_error(sock));
				continue;
    			}
     			 if(!(res = mysql_store_result(sock))) {
        ///fprintf(stderr,"Couldn't get result from %s\n",mysql_error(sock));
        		printf("Query processed\n");

        		continue;
			}

                        printf("%s has attributes below:\n",table_name);
                        int counts=0;
                        int index=1;
                         while (row = mysql_fetch_row(res))
                       {

                        printf("%d %s\n",index,row[0]);
                        counts=counts+1;
                        index=index+1;
                        }	
			mysql_free_result(res);
			printf("Type in the attribute condition to specify the data row you want to delete (ex attribute_name='VALUE')\n");
			printf("!!!Note:Add single quote for the value as shown above (Except that the value is integer)\n");
			for (i=1;i<3;i++)
			{
			fgets(name,128,stdin);
			strcpy(condition[i],name);
			///scanf("%s",condition);
			}
			sprintf(qbuffer,"Delete from ");
			strcat(qbuffer,table_name);
			strcat(qbuffer," Where ");
			strcat(qbuffer,condition[2]);
			strcat(qbuffer,";");
			
                        
     			 if(mysql_query(sock, qbuffer)) {
                                fprintf(stderr, "Query failed (%s)\n",mysql_error(sock));
                                continue;
                        }
                         if(!(res = mysql_store_result(sock))) {
        ///fprintf(stderr,"Couldn't get result from %s\n",mysql_error(sock));
                        printf("Query processed\n");

                        continue;
                        }

			 while (row = mysql_fetch_row(res))
                       {

                        printf("%s\n",row[0]);
                        
                        
                        }

		    	continue;   
			


		}

	   











	case 3://Modify Data
		{       
			sprintf(qbuffer, "show tables;");
                        connectmysql();
                        printf ("Tables:\n");

                        while (row = mysql_fetch_row(res))
                       {

                        printf("%s\n",row[0]);

                        }
                        mysql_free_result(res);
                        char table_name[50];
                        
                        printf("\nType in the exact table name that you want to update data in\n");
                        scanf("%s",table_name);
                        sprintf(qbuffer, "Select COLUMN_NAME From INFORMATION_SCHEMA.COLUMNS where TABLE_NAME='");
                        strcat(qbuffer,table_name);
                        strcat(qbuffer,"'and TABLE_SCHEMA='mads';");
                         if(mysql_query(sock, qbuffer)) {
                                fprintf(stderr, "Query failed (%s)\n",mysql_error(sock));
                                continue;
                        }
                         if(!(res = mysql_store_result(sock))) {
        ///fprintf(stderr,"Couldn't get result from %s\n",mysql_error(sock));
                        printf("Query processed\n");

                        continue;
                        }

                        printf("%s has attributes below:\n",table_name);
                        int counts=0;
                        int index=1;
                         while (row = mysql_fetch_row(res))
                       {

                        printf("%d %s\n",index,row[0]);
                        counts=counts+1;
                        index=index+1;
                        }
                        mysql_free_result(res);

			int i;
		        char *name = malloc(128);
			
			char field_change[200][200];
			char condition[200][200];
			printf("\nType in the field you want to change (ex:attribute_name='NEW VALUE')\n");
			printf("!!!Note:Add single quote for the value as shown above (Except that the value is integer)\n");
			for (i=1;i<3;i++)
                        {
                        fgets(name,128,stdin);
                        strcpy(field_change[i],name);
                        
			///scanf("%s",condition);
                        }


			///scanf("%s",field_change);
			printf("Type in the attribute condition to specify the data row you want to update (ex attribute_name='VALUE')\n");
			printf("!!!Note:Add single quote for the value as shown above (Except that the value is integer)\n"); 
			///scanf("%s",condition);
			for (i=1;i<2;i++)
                        {
                        fgets(name,128,stdin);
                        strcpy(condition[i],name);
			free(name);
                        ///scanf("%s",condition);
                        }

			sprintf(qbuffer,"update ");
			strcat(qbuffer,table_name);
			strcat(qbuffer," set ");
			strcat(qbuffer,field_change[2]);
			strcat(qbuffer, " where ");
			strcat(qbuffer,condition[1]);
			strcat(qbuffer,";");
		
                         if(mysql_query(sock, qbuffer)) {
                                fprintf(stderr, "Query failed (%s)\n",mysql_error(sock));
                                continue;
                        }
                         if(!(res = mysql_store_result(sock))) {
        ///fprintf(stderr,"Couldn't get result from %s\n",mysql_error(sock));
                        printf("Query processed\n");

                        continue;
                        }


			 while (row = mysql_fetch_row(res))
                       {

                        printf("\n%s\n",row[0]);


                        }
			


	         	mysql_free_result(res);
                        continue;


		}


           default:
		{
		
		invalid_msg();
		continue;

		}
	   break;







          }















     }




















}
