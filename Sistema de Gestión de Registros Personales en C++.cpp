/**********************************************************************
 * NOMBRE DEL PROYECTO:                                               *
 * "SISTEMA DE GESTIÓN DE REGISTROS PERSONALES EN C++"                *
 *                                                                    *
 *                                                                    *
 *                                                                    * 
 **********************************************************************/
       
#include <windows.h>                      
#include <iostream>                      
#include <conio.h>                       

using namespace std;                     

int gotoxy(USHORT x,USHORT y){                                  
COORD cp={x,y};                                                 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cp);   // sentencia gotoxy
}

/*********************** DECLARACION DE CONSTANTES *******************/

#define  TITULO  "ARREGLOS TIPO REGISTRO";
#define  TITULO1 "CAPTURA DE DATOS" ;
#define  TITULO2 "CONSULTA TIPO LISTADO" ;
#define  TITULO3 "CONSULTA SELECTIVA" ;
#define  TITULO4 "ELIMINAR";
#define  TITULO5 "MODIFICAR";

/*********************** DECLARACION DE FUNCIONES *******************/

int MENU();
void CAPTURA();
void CONSULTA_LISTADO();
void CONSULTA_SELECTIVA();
void ELIMINAR();
void MODIFICAR(void);
void CAMBIAR(int K);
void DETALLE();

int VALIDACION(long CED, int SW);

/*********************** DECLARACION DE LA ESTRUCTURA *******************/

struct CAMPOS {
   long CEDULA ;
   char NOMBRE[30];
   unsigned TEL;
   char SEXO;
   }  ;
   
/********************* DECLARACION DEL VECTOR REGISTRO *******************/
  
 CAMPOS VECTOREGISTRO[50];
 int   NRO = 0; 

/************************** PROGRAMA PRINCIPAL ***************************/

 main()
   {
   char OP = 'S';
   int  TIPO ;
   while ( OP == 'S')
     {
     TIPO = MENU();
     switch (TIPO)  {
        case 1 : CAPTURA();
                 break;
        case 2 : CONSULTA_LISTADO();
                 break;
        case 3 : CONSULTA_SELECTIVA();
                 break;
        case 4 : ELIMINAR();
                 break;
        case 5 : MODIFICAR();
                 break;
        case 6 : OP = 'N';
        };
     }
   }
    
/*************************** FUNCION M E N U **************************/
    
 int MENU()
   {
   int OPCION ;
   system("cls");
   system("color F0");
   gotoxy(29,6) ; cout << TITULO;
   gotoxy(36,8) ; cout << "M E N U";
   gotoxy(29,11); cout << "1. CAPTURA DE DATOS" ;
   gotoxy(29,12); cout << "2. CONSULTA TIPO LISTADO";
   gotoxy(29,13); cout << "3. CONSULTA SELECTIVA";
   gotoxy(29,14); cout << "4. ELIMINAR ";
   gotoxy(29,15); cout << "5. MODIFICAR ";
   gotoxy(29,17); cout << "6. SALIR";
   do  {
        gotoxy(22,20); cout << "SELECIONE UNA DE LAS ALTERNATIVAS : ";
        cin >> OPCION ;
        gotoxy(30,22); cout << "VALOR FUERA DE RANGO";
   }  while((OPCION < 1) || (OPCION > 6)) ;
   gotoxy(30,22); cout << "                          ";
   return OPCION ;
   }   
    
/************************* FUNCION CAPTURA *************************/
    
 void CAPTURA()
   {
   int SW ;
   char  OP = 'S';
   while ((OP == 'S') && ( NRO < 50))
     {
     system("cls");
     gotoxy(29,5)  ;cout << TITULO;
     gotoxy(32,7)  ;cout << TITULO1;
     gotoxy(20,11) ;cout << "CEDULA   : ";
     gotoxy(20,13) ;cout << "NOMBRE   : ";
     gotoxy(20,15) ;cout << "TELEFONO : ";
     gotoxy(20,17) ;cout << "SEXO     : ";
     do {
        gotoxy(31,11) ; cin >> VECTOREGISTRO[NRO].CEDULA ;
        gotoxy(20,24); cout<< "Error .... valor fuera de rango ";
     } while ( VECTOREGISTRO[NRO].CEDULA < 0 );
     gotoxy(20,24); cout <<"                                   ";
     SW = 0;
     SW = VALIDACION(VECTOREGISTRO[NRO].CEDULA, SW);
     if (SW == 1)
        {
        gotoxy(45,11); cout << "REGISTRO YA EXISTE";
        }
	  else
	   {
	   cin.ignore();
       gotoxy(31,13); gets( VECTOREGISTRO[NRO].NOMBRE);
       gotoxy(31,13); cout << strupr(VECTOREGISTRO[NRO].NOMBRE);
       do {
          gotoxy(31,15); cin >> VECTOREGISTRO[NRO].TEL ;
          gotoxy(20,24); cout<< "Error .... valor fuera de rango ";
       } while ( VECTOREGISTRO[NRO].TEL < 0 );
       gotoxy(20,24); cout <<"                                   ";
       do {
          gotoxy(31,17); cout<< " " ;
          gotoxy(20,24); cout << " Digite : M-> Masculino o F -> Femenino " ;
          gotoxy(31,17); VECTOREGISTRO[NRO].SEXO = getche();
          VECTOREGISTRO[NRO].SEXO = toupper(VECTOREGISTRO[NRO].SEXO) ;
       } while ((VECTOREGISTRO[NRO].SEXO != 'M') && ( VECTOREGISTRO[NRO].SEXO != 'F'));
   	   gotoxy(20,24); cout <<"                                              ";
       NRO = NRO + 1;
       }
     do {
        gotoxy(28,23); printf("DESEA CONTINUAR - S/N - ");
        OP= getch();
        OP = toupper(OP);
     } while ((OP != 'S' ) && ( OP!= 'N'));
    }
   }
   
 
 /********************** FUNCION CONSULTA TIPO LISTADO ********************/
 
  
 void CONSULTA_LISTADO() 
   {
   int  F, K ;
   if (NRO == 0)
      {
      gotoxy (20,24); cout << "No hay datos ";
      getch();
      }
    else
      {
      F = 10;
      DETALLE();
      for ( K = 0 ; K < NRO ; K++ )
        {
        gotoxy(12,F); cout << VECTOREGISTRO[K].CEDULA;
        gotoxy(24,F); cout << VECTOREGISTRO[K].NOMBRE;
        gotoxy(55,F); cout << VECTOREGISTRO[K].TEL   ;
        gotoxy(68,F); cout << VECTOREGISTRO[K].SEXO  ;
        if  ( F <= 24 )
            F++ ;
          else
            {
            gotoxy(21,F+=3); cout << "Pulse Cualquier tecla para Continuar";
            getch();
            F = 10 ;
            DETALLE();
            }
        }
	    gotoxy(21,F+=3); cout << "Pulse Cualquier tecla para Continuar";
        getch();
	  }
   }
	 
	 
/**********************  FUNCION CONSULTA SELECTIVA ***********************/ 
	 
 void CONSULTA_SELECTIVA()
   {
   long CED;	
   int K, SW ;
   char OPCION = 'S' ;
   if (NRO == 0)
      {
      gotoxy (20,22); cout << "No hay datos ";
      getch();
      }
    else
      {
      while (OPCION == 'S' )
        {
        system("cls");
        gotoxy(29,5);  cout << TITULO;
        gotoxy(31,7);  cout << TITULO3;
        gotoxy(25,11); cout << "CEDULA    : ";
        do {
           gotoxy(37,11) ; cin >> CED ; 
	       gotoxy(20,24); cout<< "Error .... valor fuera de rango ";
	    } while (CED < 0 );
	    gotoxy(20,24); cout <<"                                   ";
	    SW = 0;
	    for (K = 0 ; K < NRO && SW == 0 ; K ++ )
	        if (CED == VECTOREGISTRO[K].CEDULA )
     	       {
     	       SW = 1;
		       gotoxy(25,13); cout << "NOMBRE    = " << VECTOREGISTRO[K].NOMBRE;
		       gotoxy(25,15); cout << "TELEFONO  = " << VECTOREGISTRO[K].TEL   ;
		       gotoxy(25,17); cout << "SEXO      = " << VECTOREGISTRO[K].SEXO  ;
               }
        if (SW == 0)
           {
           gotoxy(50,11) ; cout << "NO EXISTE REGISTRO" ;
           }
        do {
           gotoxy(28,22); printf("DESEA CONTINUAR - S/N - ");
           OPCION = getch();
	       OPCION = toupper(OPCION);
	    } while (( OPCION != 'S' ) && ( OPCION != 'N'));
	    }
	  }	  
   }
	  
/************************ FUNCION ELIMINAR *************************/
	 
 void ELIMINAR()
   {
   char OP = 'S' ;
   long CED ;
   int K , W , SW ;
   while ((OP == 'S' ))   
     {
     if ( NRO == 0 )
        {
	    gotoxy (20,24); cout << "No hay datos                        ";
	    OP = 'N'; getch();
	    }
	  else
	    {
	    system("cls");
	    gotoxy(29,5);  cout << TITULO;
        gotoxy(36,7);  cout << TITULO4;
        gotoxy(25,11); cout << "CEDULA    : ";
        do {
           gotoxy(37,11) ; cin >> CED ;
	       gotoxy(20,24); cout<< "Error .... valor fuera de rango ";
	    } while (CED < 0 );
	    gotoxy(20,24); cout <<"                                      ";
	    SW = 0 ;
	    for (K = 0 ; K < NRO && SW == 0; K ++ )
	      if (CED == VECTOREGISTRO[K].CEDULA )
	         {
		     gotoxy(25,13); cout << "NOMBRE    = " << VECTOREGISTRO[K].NOMBRE;
		     gotoxy(25,15); cout << "TELEFONO  = " << VECTOREGISTRO[K].TEL   ;
		     gotoxy(25,17); cout << "SEXO      = " << VECTOREGISTRO[K].SEXO  ;
		     SW = 1;
		     for ( W = K ; W < NRO ; W++ ) 
			     VECTOREGISTRO[W] = VECTOREGISTRO[W+1];
			 NRO = NRO - 1 ; 
			 gotoxy(50,11); cout << "Elemento Eliminado";
		     }
        if (SW == 0)
           {
           gotoxy(50,11) ; cout << "NO EXISTE REGISTRO" ;
           }
        do {
		   gotoxy(28,24); printf("DESEA CONTINUAR - S/N - ");
		   OP = getch();
		   OP = toupper(OP);
		   } while (( OP != 'S' ) && ( OP != 'N'));
		}
	 }	
   }
       
 /************************ FUNCION MODIFICAR REGISTRO **********************/ 
    
 void MODIFICAR()
   {
   int K, SW ;
   char OPCION = 'S' ;
   long CED ;
   if (NRO == 0)
      {
      gotoxy (20,24); cout << "No hay datos ";
      getch();
      }
     else
      {
      while (OPCION == 'S' )
        {
	 	system("cls");
        gotoxy(29,5);  cout <<  TITULO ;
	    gotoxy(36,6);  cout <<  TITULO5 ;
	    gotoxy(20,11); cout << "CEDULA   : ";
	    cin.sync();
	    do {
	       gotoxy(31,11) ; cin >> CED ;
	       gotoxy(20,24); cout<< "Error .... valor fuera de rango ";
        } while ( CED < 0 ) ;
	    gotoxy(20,24); cout << "                                   ";
	    SW = 0;
	    for (K = 0 ; K < NRO && SW == 0 ; K ++ )
	      if (CED == VECTOREGISTRO[K].CEDULA )
     	     {
     	     SW = 1;
		     gotoxy(20,13); cout << "NOMBRE   = " << VECTOREGISTRO[K].NOMBRE;
		     gotoxy(20,15); cout << "TELEFONO = " << VECTOREGISTRO[K].TEL   ;
		     gotoxy(20,17); cout << "SEXO     = " << VECTOREGISTRO[K].SEXO  ;
		     CAMBIAR(K);
	         gotoxy(50,11); cout << "REGISTRO MODIFICADO";
             }
        if (SW == 0)
           {
           gotoxy(50,11) ; cout << "NO EXISTE REGISTRO" ;
           }
        do {
           gotoxy(28,24); printf("DESEA CONTINUAR - S/N - ");
           OPCION = getch();
	       OPCION = toupper(OPCION);
	    } while (( OPCION != 'S' ) && ( OPCION != 'N'));
	    }
     }
   }  
    
 /*********************************** CAMBIAR **********************************/ 
 
 void CAMBIAR(int K)
   {
   int OP = 1,F = 13;
   char TECLA;
   gotoxy(20,21);cout<<"UTILICE : Flechas Abajo y Arriba Para Desplazarse, ENTER para seleccionar y Terminar";
   do {
	  gotoxy(31,F); TECLA = getch();
	  if ( kbhit()) 
	     {	
	     TECLA = getch();
		 if (TECLA == 80)    // Baja
		    {
		    OP++;
		    F+=2;
		    }
		 if (TECLA == 72)   // Sube
		    {
		    OP--;
		    F-=2;
		    }
		 if ((OP > 3) ||  (OP < 1))
			{
			OP = 1;
		    F = 13;
			} 
		 }
  } while ((TECLA == 80) ||(TECLA == 72)) ; 
	
	
  switch (OP){ 
	 case 1: cin.sync();
	         gotoxy(31,13); cout << "                                ";
		     gotoxy(31,13); gets( VECTOREGISTRO[K].NOMBRE);
             gotoxy(31,13); cout << strupr(VECTOREGISTRO[K].NOMBRE);
	         break;
	 case 2: do {
			    gotoxy(31,15) ; cout <<"           " ;
			    gotoxy(31,15); cin >> VECTOREGISTRO[K].TEL ;
                gotoxy(20,24); cout<< "Error .... valor fuera de rango ";
             } while ( VECTOREGISTRO[K].TEL < 0 );
             gotoxy(20,24); cout <<"                                   ";
		     break;
	 case 3: do {
                gotoxy(31,17) ; cout << "  ";
                gotoxy(20,24); cout << " Digite : M-> Masculino o F -> Femenino " ;
                gotoxy(31,17); VECTOREGISTRO[K].SEXO = getche();
                VECTOREGISTRO[K].SEXO = toupper(VECTOREGISTRO[K].SEXO) ;
             } while ((VECTOREGISTRO[K].SEXO != 'M') && ( VECTOREGISTRO[K].SEXO != 'F'));
		     gotoxy(20,24); cout << "                                           ";
			 break;
		}
  gotoxy(20,21);cout<<"                                                                               ";
  }	
   
    

/************************* FUNCION DETALLE ****************************/

 void DETALLE()
   {
   system("cls");
   gotoxy(29,3) ; cout << TITULO;
   gotoxy(30,5) ; cout << TITULO2;
   gotoxy(12,8) ; printf("CEDULA      NOMBRE                         TELEFONO     SEXO ");
   }
 
 
/******************* FUNCION VALIDACION *********************/
  

int VALIDACION(long CED, int SW)
  {
  int K;
  for (K = 0 ; K < NRO && SW == 0 ; K ++ )
    if (CED == VECTOREGISTRO[K].CEDULA )
  	   {
   	   SW = 1;
	   gotoxy(20,13); cout << "NOMBRE    = " << VECTOREGISTRO[K].NOMBRE;
	   gotoxy(20,15); cout << "TELEFONO  = " << VECTOREGISTRO[K].TEL   ;
	   gotoxy(20,17); cout << "SEXO      = " << VECTOREGISTRO[K].SEXO  ;
	   }
  return SW;
  }
