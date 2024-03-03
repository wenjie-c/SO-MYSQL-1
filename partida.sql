drop database if exists juego;
create database juego;
use juego;
create table Partida (JugadorA integer, JugadorB integer, chat_id integer);
insert into Partida (JugadorA, JugadorB, chat_id) values (1,2,1);
insert into Partida (JugadorA, JugadorB, chat_id) values (2,3,2);
insert into Partida (JugadorA, JugadorB, chat_id) values (4,5,3);