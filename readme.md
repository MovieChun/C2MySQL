#This is a service for C to MySQL

##Frist
	open the MySQL:
		$sudo service mysql start
		#if you can't start it,place check you ip in /etc/mysql/my.cnf .
		$mysql -u root -p
		password:111

	about the gcc:
		1.You should install the lib of MySQL:
			$sudo apt-get install libmysqlclient-dev
			#Then you can get heads in /usr/include/mysql ang the library in /usr/lib/mysql

		2.How to use the mysql.h:
			#include<mysql/mysql.h>
		or
			$gcc -c m.c -I /usr/include/mysql/
			#The m.c mean your C file. And the -I will point the folder of your heads. It will make the m.o file.

		3.make the objective:
			$gcc m.o -o m.run -L /usr/lib/ -/mysqlclient


		4.run:
			$./m.run

