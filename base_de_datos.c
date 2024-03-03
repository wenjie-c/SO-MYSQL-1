#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Programa simple para devolver una consulta

int main(int argc, char *argv[]) {
	
	// --- Inicializar la conexión ---
	MYSQL * cnx;
	MYSQL_RES * resultado;
	MYSQL_ROW row;
	int JugadorA;
	int JugadorB;
	int chat_id;
	
	int err;
	cnx = mysql_init(NULL);
	if(cnx == NULL){
		printf("Error al crear la conexion: %u &s\n", mysql_errno(cnx),mysql_error(cnx));
		exit(1);
	}
	
	cnx = mysql_real_connect (cnx, "localhost", "root", "mysql", NULL, 0, NULL, 0);
	
	if(cnx == NULL){
		printf("Error al crear la conexion: %u &s\n", mysql_errno(cnx),mysql_error(cnx));
		exit(1);
	}
	
	// --- Fin de la inicializacion ---
	
	// --- Creacion de la base de datos y de la tabla
	mysql_query(cnx, "drop database if exists juego");
	err=mysql_query(cnx, "create database juego");
	if(err!= 0){
		printf("Error al crear la base de datos: %u &s\n", mysql_errno(cnx),mysql_error(cnx));
		exit(1);
	}
	
	err=mysql_query(cnx, "use juego");
	err=mysql_query(cnx, "create table Partida (JugadorA integer, JugadorB integer, chat_id integer)");
	if(err!= 0){
		printf("Error al crear la tabla: %u &s\n", mysql_errno(cnx),mysql_error(cnx));
		exit(1);
	}
	
	// --- Fin de la creacion de la base de datos y de la tabla ---
	
	// --- Introducción de datos como ejemplo ---
	err=mysql_query(cnx, "insert into Partida (JugadorA, JugadorB, chat_id) values (1,2,1)");
	err=mysql_query(cnx, "insert into Partida (JugadorA, JugadorB, chat_id) values (2,3,2)");
	err=mysql_query(cnx, "insert into Partida (JugadorA, JugadorB, chat_id) values (4,5,3)");
	if(err!= 0){
		printf("Error al insertar datos: %u &s\n", mysql_errno(cnx),mysql_error(cnx));
		exit(1);
	}
	// --- Fin de la introducir datos ---
	
	// --- Consulta ---
	err=mysql_query(cnx,"select * from Partida");
	
	resultado = mysql_store_result(cnx);
	row = mysql_fetch_row(resultado);
	
	if(row ==NULL){
		printf("No se ha encontardo el dato especificado\n");
		
	}
	else{
		while(row !=NULL){
			JugadorA = atoi(row[0]);
			JugadorB = atoi(row[1]);
			chat_id = atoi(row[2]);
			printf("Id del Jugador A: %d \n", JugadorA);
			printf("Id del Jugador B: %d \n", JugadorB);
			printf("Id del chat: %d \n", chat_id);
			row = mysql_fetch_row(resultado);
		}
	}
	mysql_close(cnx);
	
	
	return 0;
}

