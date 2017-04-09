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
	char *database = "test_mysql";

	conn = mysql_init(NULL);
	if(!mysql_real_connect(conn,server,user,password,database,0,NULL,0)){
		printf("%s\n",mysql_error(conn));
		return 1;
	}
	else
		printf("connect MySQL OK!\n");


	return 0;
}



