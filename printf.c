#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>

//Programa creado Por Jose Gallardo
//Fue creado para poder entender el uso del comando printf();

int main(void) {
	
	printf("[+] Modo de uso: ");
	printf("Ingrese 3 numeros: \n\t--> 123 123.3 123.345 [enter] \n\t\t o \n\t--> 123 [enter] \n\t--> 123.3 [enter] \n\t--> 123.345 [enter]\n\n\n");
	
	// Ingreso de Numeros consecutivos con scanf
	int a;
	float b;
	double c;
	printf("Ingrese 3 numeros: ");
	scanf("%i %f %lf",&a, &b, &c);
		//Es lo mismo que hacer: 
	/*scanf("%i",&a);
	scanf("%f",&b);
	scanf("%lf",&c);
	*/
	
	// Salida Standar printf();
	
	/*
	%c -> caracter
	%d o %i -> entero con signo
	%u -> entero sin signo
	%f -> float (decimal normal)
	%lf -> double
	%e -> notacion cientifica
	%g -> elige automaticamente %e o %f
	%s -> cadena de caracteres
	%o -> octal
	%x -> hexadecimal
	%p -> direccion de puntero
	*/
	printf("[+] El primer numero ingresado en caracter ASCII es: %c\n", a); // muestra el valor del numero en caracter del codigo ASCII
	printf("[+] Lo que ingresamos se muestra en el siguiente orden: %%i, %%f, %%lf --> %i, %f, %lf\n", a, b, c); // en caso de que sea float o int que en scanf hayamos puesto un %f o un %lf o un %i
	// %%s -> salta el porcentaje, hace que se pueda mostrar pon pantalla en %s  sin ser remplazada por una variable
	printf("[+] El segundo numero en formato cientifico es: %e\n", b); // Muestra en formato cientifico
	printf("[+] El segundo numero ingresado se elige automaticamente entre %%f o %%e: %g\n", b); // Elije automaticamente entre %f y %e, elimina ceros innecesarios
	//printf("lo que ingresamos fue: %s", a); // cadena de caracteres
	printf("[+] El primer numero ingresado en octal es: %o\n", a); // Conversion a octal
	printf("[+] El primer numero ingresado en hexadecimal es: %x\n", a); // conversion a hexadecimal
	printf("[+] El puntero (direccion de memoria) de los tres numero ingresados es: %p, %p, %p\n\n\n", (void*)&a, (void*)&b, (void*)&c); // muestra el puntero, lugar en memoria de donde se guardan las variables
	/*
	Porque hacemos (void*)? la respuesta es que para mostrar la direccion del puntero debemos transformar todo a un puntero que apunte a cualquier cosa, osea un puntero generico.
	ya que &a, &b, $c son punteros que apuntan a su unico tipo, osea el a apunta a *int entonces debemos transformar todo a un puntero generico
	*/
	//sleep(5);
	//system("cls");
	
	
	printf("\tModificadores de TIPO....");
		//Longitud de un numero
	/*
		%ld: Long int 
		%hd: short int 
		%lf: double --> importante para double siempre usar %lf
	*/
	
		//Presicion y  ancho para %f 
	/*
	%10.2f -> ancho total de 10 caracteres, 2 decimales ajustado a la derecha
	%-10.2f -> ajustado a la izquierda
	%.3f -> solo especifica decimales (ancho automatico)
	*/
	
		//Para cadenas %s
	/*
	%10.5s -> minimo 10 caracteres, maximo 5 (se trunca si es mas larga)
	%-10.5s -> alineado a la izquierda
	*/
	
		//Secuencias de escape
	/*
	\n -> Salto de linea
	\t -> Tabulador
	\" -> Comillas dobles
	\\ -> barra invertida
	*/
	
	//Con prinf() se puede usar %d, %f etc, es decir, podemos usar formatos es por eso  asi como controlar ancho de decimales y la alineacion asi como algunas secuencias de escape
	
	
					//Que significa la alineacion a la derecha o la izquierda?
	char TEXTO[10];
	float numero=65.41238974662;
	printf("\nEjemplo con el primer numero 65.41238974662\n");
	printf("[+] Se reserva 10 caracteres y 2 decimales ajustado a la derecha: %10.2f\n",numero); //se corta en 2 decimales
	printf("[+] Se reserva 10 caracteres y 2 decimales ajustado a la izquierda: %-10.2f\n",numero); //se corta en 2 decimales
	printf("[+] Solo se escifica 3 decimales: %.3f\n",numero); //se corta solo en 2 decimales
	
	printf("\n\nEjemplo con el numero 73");
	printf("\n[+] Reserva 10 caracteres ajustado a la derecha: %10d\n", 73);
	printf("[+] Reserva 10 caracteres ajustado a la izquierda: %-10d\n", 73);
	
	
	printf("\n\nIngrese un texto de mas de 5 caracteres: "); scanf("%s", TEXTO);
	printf("[+] Se reserva 10 caracteres a la derecha: %10s\n", TEXTO);
	printf("[+] Se reserva 10 caracteres a la izquierda: %-10s\n", TEXTO);
	printf("[+] Reserva al menos 10 espacios, pero corta la cadena a 5 letras alineado a la derecha: %10.5s\n",TEXTO);
	printf("[+] Reserva al menos 10 espacios, pero corta la cadena a 5 letras alineado en la izquierda: %-10.5s\n",TEXTO);
	printf("[+] Muestra la cadena completa, puede ser mas de 10 caracteres: %10s\n",TEXTO);
	printf("[+] Sin el ancho, solo corta la cadena a 5 caracteres, sin reservar espacios: %.5s\n",TEXTO);
	
	printf("\n\nPueden servir para hacer TABLAS todo esto, ahora un ejemplo\n\n");
	
	//printf("Ingrese un nombre: ");
	//scanf("%s",nombre); --> asi sin ciclos solo sirve para ingresar un solo nombre, no hace falta ponerte "[]", ni el "&"
	char users[5][10]; // --> Esto me dice que voy a ingresar 5 nombres, cada uno con hasta 9 letras //9 letras porque se reserva el \0 para el fin de linea
	for(int i=0; i<5; i++){
		printf("[+]Ingrese un nombre de almenos de 5 caracteres: ");
		scanf("%9s",users[i]);
		//En scanf no se pone el %.9s como el printf(), se usa el %9s para decirle que queremos leer solo 9 caracteres
		//Lo que pasa es que si ingresamos mas de 9 caracteres se trunca en solo 9 caracteres, pero ocurre un problema
		//Las demas letras que ingresamos no se pierden, solo se guardan en el buffer del teclado, por lo que si ingresamos: supercaligrafistico
		//solo vamos a leer la palabra "supercali", y el resto de las palabras se van a insertar automaticamente en el siguiente texto que tengamos que ingresar
		//por eso es impotante limpiar el buffer antes de ingresar un nuevo nombre
	}
	
	//CREACION DE LA TABLA
	
	printf("\n%85s","--------------------------------------------------\n");
	printf("%35s %25s %22s\n", "|","TABLA","|");
	printf("%85s","--------------------------------------------------\n");
	printf("%35s %-2s %s %-10s %s %-15s %s %-10s %s\n","|", "id", "|", "user", "|", "password", "|", "membership", "|");
	printf("%85s","--------------------------------------------------\n");
	printf("%35s %-2s %s %-10s %s %-15s %s %-10s %s\n","|", "1", "|", users[0], "|", "pepito123", "|", "1 mes", "|");
	printf("%35s %-2s %s %-10s %s %-15s %s %-10s %s\n","|", "2", "|", users[1], "|", "error404", "|", "12 meses", "|");
	printf("%35s %-2s %s %-10s %s %-15s %s %-10s %s\n","|", "3", "|", users[2], "|", "passworddd", "|", "24 meses", "|");
	printf("%35s %-2s %s %-10s %s %-15s %s %-10s %s\n","|", "4", "|", users[3], "|", "a", "|", "3 meses", "|");
	printf("%35s %-2s %s %-10s %s %-15s %s %-10s %s\n","|", "5", "|", users[4], "|", "muydificil123", "|", "10 meses", "|");
	printf("%85s","--------------------------------------------------\n");
	
	//esta tabla solo es una prueba, ninguna password existe ni ningun usuario
	return 0;
}

