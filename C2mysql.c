#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>


int main(){
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	char *server = "localhost";
	char *user = "root";
	char *password = "123";
	char database[20] = "student_sql";
	
	char com_str[100];
	int  rc,i,fields;
	int rows;

	conn = mysql_init(NULL);
	if(!mysql_real_connect(conn,server,user,password,database,0,NULL,0)){
		printf("%s\n",mysql_error(conn));
		return 1;
	}

	while(1){
		printf("\n\ncommon:\t");
		gets(com_str);
		printf("%s\n",com_str);
		rc = mysql_real_query(conn,com_str,strlen(com_str));
		if(rc != 0){
			printf("mysql error:%s",mysql_error(conn));

		}else{
			res = mysql_store_result(conn);
			if(res != NULL){
				rows = mysql_num_rows(res);
				fields = mysql_num_fields(res);
				while(row = mysql_fetch_row(res)){
					for(i = 0;i < fields;i++)
						printf("%s\t",row[i]);
					printf("\n");
				}
			}
		}
	}


	mysql_close(conn);

	return 0;
}



