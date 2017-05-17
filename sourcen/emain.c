#include "simuc.h"

///////////////////////////////////////////////////////////////////////////////////////
// Bedingte Compilierung zur Bestimmung welches "Beispiel" compiliert werden soll  ///
//
// Es darf immer nur ein "define" aktive, d.h. nicht auskommentiert, sein.
//
//#define V1_Aufgabe_1
//#define V1_Aufgabe_1_loesung_a
//#define V1_Aufgabe_2
//#define V1_Aufgabe_2_loesung
//#define V1_Aufgabe_3
#define V1_Aufgabe_3_loesung
//
///////////////////////////////////////////////////////////////////////////////////////


#ifdef V1_Aufgabe_1

void emain(void* arg) 
{
    unsigned short int zahl1;
    unsigned short int zahl2;
    unsigned short int ergebnis;
    char string_1[4]; // wert auf 4 stellen festgelegt
    char string_2[4]; // wert auf 4 stellen festgelegt
    char string_aus[30];
    char string_erg[4];

	
	INIT_BM_WITHOUT_REGISTER_UI;
	


    do{
        putstring("Bitte 1. Zahl eingeben:\n");
        getstring(string_1);
    }while(string_1<0 && string_1>9);

	zahl1=stringtoi(string_1);


    do{
        putstring("Bitte 2. Zahl eingeben:\n");
        getstring(string_2);
    }while(string_2<0 && string_2>9);

    zahl2=stringtoi(string_2);

    ergebnis= zahl1 + zahl2;

    itostring(ergebnis, string_erg);

    copystring("Summe beider Zahlen ist:\n",string_aus);
    appendstring(string_erg,string_aus);
    putstring(string_aus);

    unsigned short int stringtoint(char string_ein[]){
        int i;
        unsigned short int erg;

        for(i=0;i<4;i++){
            if(string_ein[i]!=null){

            }
        }

        return erg;
    }

	END;
}
#endif // V1_Aufgabe_1

#ifdef V1_Aufgabe_1_loesung_a
void emain(void* arg)
{
    unsigned short int zahl1=0;
    unsigned short int zahl2=0;
    unsigned short int ergebnis;
    char string_1[100];
    char string_2[100];


    INIT_BM_WITHOUT_REGISTER_UI;
    int i;
    boolean test=0;     //Testvariable für die while-Schleife
    while (test==0){
    putstring("Bitte 1. Zahl mit höchstens vier Ziffern eingeben:\n");
    getstring(string_1);
    if (strlen(string_1)<5){
        test=1;
        for (i = 0; i<strlen(string_1); i++){
           if (!(string_1[i]>='0'&&string_1[i]<='9')){
               test=0;
           }
        }
        }
    if (test==0){
        putstring("Die Eingabe war falsche! ");
    }
    }

    if(strlen(string_1)==1){    //hätte auch switch-case verwenden können
        zahl1=string_1[0]-48;
    }else{
        if(strlen(string_1)==2){
            zahl1=10*(string_1[0]-48)+string_1[1]-48;
       }else{
            if(strlen(string_1)==3){
                zahl1=100*(string_1[0]-48)+10*(string_1[1]-48)+string_1[2]-48;
            }else{
                zahl1=1000*(string_1[0]-48)+100*(string_1[1]-48)+10*(string_1[2]-48)+string_1[3]-48;
            }
        }
    }

    boolean test2=0;
    while (test2==0){
    putstring("Bitte 2. Zahl mit höchstens vier Ziffern eingeben:\n");
    getstring(string_2);
    if (strlen(string_2)<5){
        test2=1;
        for (i = 0; i<strlen(string_2); i++){
           if (!(string_2[i]>='0'&&string_2[i]<='9')){
               test2=0;
           }
        }
        }
    if (test2==0){
        putstring("Die Eingabe war falsche! ");
    }
    }

    if(strlen(string_2)==1){
        zahl2=string_2[0]-48;
    }else{
        if(strlen(string_2)==2){
            zahl2=10*(string_2[0]-48)+string_2[1]-48;
       }else{
            if(strlen(string_2)==3){
                zahl2=100*(string_2[0]-48)+10*(string_2[1]-48)+string_2[2]-48;
            }else{
                zahl2=1000*(string_2[0]-48)+100*(string_2[1]-48)+10*(string_2[2]-48)+string_2[3]-48;
            }
       }
    }

    ergebnis= zahl1 + zahl2;
    if (ergebnis<10){
        string_1 [0]=ergebnis+48;
    }else{
        if(ergebnis<100){
            string_1[0]=ergebnis/10+48;
            string_1[1]=ergebnis%10+48;
        }else{
            if(ergebnis<1000){
                string_1[0]=ergebnis/100+48;
                string_1[1]=(ergebnis/10)%10+48;
                string_1[2]=ergebnis%10+48;
            }else{
                string_1[0]=ergebnis/1000+48;
                string_1[1]=(ergebnis/100)%10+48;
                string_1[2]=(ergebnis/10)%10+48;
                string_1[3]=(ergebnis%10)+48;
            }
        }
    }


    copystring("Summe beider Zahlen ist:\n",string_2);
    appendstring(string_1, string_2);
    putstring (string_2);

    END;
}
#endif // V1_Aufgabe_1_loesung_a

#ifdef V1_Aufgabe_2

void emain(void* arg) 
{
	unsigned short int T1, T2;
	unsigned short int temp, help;

	// Mit den folgenden beiden Defines kann bestimmt werden welche Simulations-Tools verwendet werden.
	// Diese MUESSEN dann auch gestartet werden.
	// ######### IN DIESEM VERSUCH MUESSEN SIE OHNE DAS BANDMODELL ARBEITEN,             ##############
	// ######### da dieses sonst die Eingabe ueber das User-Interface "ueberschreibt".   ##############
	//INIT_BM_WITH_REGISTER_UI;		// Es werden beide Simulations-Tools (Bandmodell.exe und User_Interface.exe) verwendet
	INIT_REGISTER_UI_WITHOUT_BM		// Es wird nur das User-Interface zur Registerdarstellung (User_Interface.exe) verwendet.




	// Initialisierung gemaess Unterpunkt b)
	temp = (1 << 5) | (1 << 4); // temp mit dem Bitmuster 0x0030 
								// initialisieren bei dem nur Bit 5 							
								// und Bit 4 gesetzt (1) sind

	temp = ~temp;				// Alle Bits von temp negieren 								
								// temp enthält nun das
								// Bitmuster 0xFFCF

	io_out16 (DIR1, ( io_in16(DIR1) & temp) );	// Nur Bit 5 und 4 den
											// Wert 0 ( Lesen ) geben und
											// alle anderen Bits unverändert
											// lassen.

	temp = (1 << 10) | (1 << 9);	
	io_out16 (DIR1, ( io_in16(DIR1) |  temp) ); // Nur Bit 10 und 9 
											// auf 1 (Schreiben) setzen. Alle
											// anderen Bits unverändert
											// lassen.

	while(1) {

		SYNC_SIM;		

		temp = io_in16(IN1);		// Einlesen von Port 1	

		temp = temp >> 4;	// So oft nach rechts shiften
							// bis das Bit 4 an der Bitstelle 0 steht.

		T1 = temp & 0x01;	// Zur Sicherheit alle Bits, 
							// bis auf Bit0 auf 0 setzen 
							// und das Ergebnis T1 zuweisen.
		/*	Das Bit für den Taster T1 ist nun eingelesen und 
		die Variablen T1 hat genau den logischen Wert dieses
		Bits, d.h.
		T1 = 0 wenn Bit 4 = 0 , also wenn Taster T1 betätigt.
		T1 = 1 wenn Bit 4 = 1 , also wenn Taster T1 nicht betätigt.
		Für T2 machen wir nun das Gleiche.
		*/
		temp = in(IN1);		// Einlesen von Port 1	

		temp = temp >> 5;	// So oft nach rechts shiften
							// bis das Bit 5 an der Bitstelle 0 steht.

		T2 = temp & 0x01;	// Alle Bits, bis auf Bit0 auf 0 setzen 
							// und das Ergebnis T2 zuweisen.

		if(T1 == 1) {		
			temp = 1 << 9;	// Berechnung des Bitmusters 0x0200 						
							// bei dem nur das Bit 9 gesetzt ist.

			// Bit 9 an Port 1 auf '1' setzen.
			help = io_in16(OUT1); 			// Aktuellen Ausgabewert einlesen ...
			help = help |  temp;			// ... mit temp "verodern"...
			io_out16(OUT1, ( help | temp) );	 // ... und wieder ausgeben.
			
			// Dies waere die kuerzere Varianten um Bit 9 zu setzen
			// io_out16 (OUT1, ( io_in16(OUT1) |  temp) );
		}
		else {
			temp = 1 << 9;	// Berechnung des Bitmusters 0x0200 

			temp = ~temp;	// Das Bitmuster wird bitweise
							// invertiert, d.h. nun ist Bit 9 das
							// einzige Bit das '0' ist.

			// Bit 9 an Port 1 wird zurueck gesetzt auf '0
			io_out16 (OUT1, ( io_in16(OUT1) & temp) );
			
		}

		if(T2 == 1) {		
			temp = 1 << 10;
			io_out16 (OUT1, ( io_in16(OUT1) |  temp) );
		}		
		else {
			temp = 1 << 10;
			temp = ~temp;
			io_out16 (OUT1, ( io_in16(OUT1) & temp) );
		}
	}		

	
	END;
}
#endif // V1_Aufgabe_2

#ifdef V1_Aufgabe_2_loesung
void emain(void* arg)
{
    unsigned short int T1, T2;
    unsigned short int temp, help, start;
    unsigned short int i=0;

    // Mit den folgenden beiden Defines kann bestimmt werden welche Simulations-Tools verwendet werden.
    // Diese MUESSEN dann auch gestartet werden.
    // ######### IN DIESEM VERSUCH MUESSEN SIE OHNE DAS BANDMODELL ARBEITEN,             ##############
    // ######### da dieses sonst die Eingabe ueber das User-Interface "ueberschreibt".   ##############
    //INIT_BM_WITH_REGISTER_UI;		// Es werden beide Simulations-Tools (Bandmodell.exe und User_Interface.exe) verwendet
    INIT_REGISTER_UI_WITHOUT_BM		// Es wird nur das User-Interface zur Registerdarstellung (User_Interface.exe) verwendet.


    while(1) {

        SYNC_SIM;

        temp = io_in16(IN1);		// Einlesen von Port 1

        temp = temp >> 4;	// So oft nach rechts shiften
                            // bis das Bit 4 an der Bitstelle 0 steht.

        T1 = temp & 0x01;	// Zur Sicherheit alle Bits,
                            // bis auf Bit0 auf 0 setzen
                            // und das Ergebnis T1 zuweisen.
        /*	Das Bit für den Taster T1 ist nun eingelesen und
        die Variablen T1 hat genau den logischen Wert dieses
        Bits, d.h.
        T1 = 0 wenn Bit 4 = 0 , also wenn Taster T1 betätigt.
        T1 = 1 wenn Bit 4 = 1 , also wenn Taster T1 nicht betätigt.
        Für T2 machen wir nun das Gleiche.
        */
        temp = io_in16(IN1);		// Einlesen von Port 1

        temp = temp >> 5;	// So oft nach rechts shiften
                            // bis das Bit 5 an der Bitstelle 0 steht.

        T2 = temp & 0x01;	// Alle Bits, bis auf Bit0 auf 0 setzen
                            // und das Ergebnis T2 zuweisen.


        if(i==0){           //start festelgen
           start = 0x4000;
           io_out16(DIR1, start);
        }


        temp = (1 << 14) | (1 << 13) | (1 << 12) | (1 << 11); // Bitmuster =0x3c00 -- nur bit 14,13,12,11 = 1

        help = io_in16(DIR1); 			// Aktuellen Ausgabewert einlesen
        help = help & temp;             // Alle Bits Ausser 14,13,12,11 auf 0

        help = help >> 11;              // Sodass Bit 11 an Bit stelle 0 ist




        // Kreislauf der Lichts (rechts herum)
        if(T1 == 1 && T2 == 0) {
           switch(help){
                case 1 : help = 2; break;
                case 2 : help = 4; break;
                case 4 : help = 8; break;
                case 8 : help = 1; break;
           }
        }

        // Kreislauf der Lichts (links herum)
        else if(T1 == 0 && T2 == 1) {
           switch(help){
                case 8 : help = 4; break;
                case 4 : help = 2; break;
                case 2 : help = 1; break;
                case 1 : help = 8; break;
           }
        }


        help = help << 11;

        io_out16(DIR1, help);
        i++;
    }


    END;





}
#endif //V1_Aufgabe_2_loesung



#ifdef V1_Aufgabe_3

void emain(void* arg) 
{
	unsigned short int T1, T2;
	unsigned short int temp, help;

	// Mit den folgenden beiden Defines kann bestimmt werden welche Simulations-Tools verwendet werden.
	// Diese MUESSEN dann auch gestartet werden.
	// ######### IN DIESEM VERSUCH MUESSEN SIE OHNE DAS BANDMODELL ARBEITEN,             ##############
	// ######### da dieses sonst die Eingabe ueber das User-Interface "ueberschreibt".   ##############
	//INIT_BM_WITH_REGISTER_UI;		// Es werden beide Simulations-Tools (Bandmodell.exe und User_Interface.exe) verwendet
	INIT_REGISTER_UI_WITHOUT_BM		// Es wird nur das User-Interface zur Registerdarstellung (User_Interface.exe) verwendet.




	// Initialisierung gemaess Unterpunkt b)
	temp = (1 << 5) | (1 << 4); // temp mit dem Bitmuster 0x0030 
								// initialisieren bei dem nur Bit 5 							
								// und Bit 4 gesetzt (1) sind

	temp = ~temp;				// Alle Bits von temp negieren 								
								// temp enthält nun das
								// Bitmuster 0xFFCF

	io_out16 (DIR1, ( io_in16(DIR1) & temp) );	// Nur Bit 5 und 4 den
											// Wert 0 ( Lesen ) geben und
											// alle anderen Bits unverändert
											// lassen.

	temp = (1 << 10) | (1 << 9);	
	io_out16 (DIR1, ( io_in16(DIR1) |  temp) ); // Nur Bit 10 und 9 
											// auf 1 (Schreiben) setzen. Alle
											// anderen Bits unverändert
											// lassen.

	while(1) {

		SYNC_SIM;		

		temp = io_in16(IN1);		// Einlesen von Port 1	

		temp = temp >> 4;	// So oft nach rechts shiften
							// bis das Bit 4 an der Bitstelle 0 steht.

		T1 = temp & 0x01;	// Zur Sicherheit alle Bits, 
							// bis auf Bit0 auf 0 setzen 
							// und das Ergebnis T1 zuweisen.
		/*	Das Bit für den Taster T1 ist nun eingelesen und 
		die Variablen T1 hat genau den logischen Wert dieses
		Bits, d.h.
		T1 = 0 wenn Bit 4 = 0 , also wenn Taster T1 betätigt.
		T1 = 1 wenn Bit 4 = 1 , also wenn Taster T1 nicht betätigt.
		Für T2 machen wir nun das Gleiche.
		*/
		temp = in(IN1);		// Einlesen von Port 1	

		temp = temp >> 5;	// So oft nach rechts shiften
							// bis das Bit 5 an der Bitstelle 0 steht.

		T2 = temp & 0x01;	// Alle Bits, bis auf Bit0 auf 0 setzen 
							// und das Ergebnis T2 zuweisen.

		if(T1 == 1) {		
			temp = 1 << 9;	// Berechnung des Bitmusters 0x0200 						
							// bei dem nur das Bit 9 gesetzt ist.

			// Bit 9 an Port 1 auf '1' setzen.
			help = io_in16(OUT1); 			// Aktuellen Ausgabewert einlesen ...
			help = help |  temp;			// ... mit temp "verodern"...
			io_out16(OUT1, ( help | temp) );	 // ... und wieder ausgeben.
			
			// Dies waere die kuerzere Varianten um Bit 9 zu setzen
			// io_out16 (OUT1, ( io_in16(OUT1) |  temp) );
		}
		else {
			temp = 1 << 9;	// Berechnung des Bitmusters 0x0200 

			temp = ~temp;	// Das Bitmuster wird bitweise
							// invertiert, d.h. nun ist Bit 9 das
							// einzige Bit das '0' ist.

			// Bit 9 an Port 1 wird zurueck gesetzt auf '0
			io_out16 (OUT1, ( io_in16(OUT1) & temp) );
			
		}

		if(T2 == 1) {		
			temp = 1 << 10;
			io_out16 (OUT1, ( io_in16(OUT1) |  temp) );
		}		
		else {
			temp = 1 << 10;
			temp = ~temp;
			io_out16 (OUT1, ( io_in16(OUT1) & temp) );
		}
	}		

	
	END;
}
#endif // V1_Aufgabe_3

#ifdef V1_Aufgabe_3_loesung
void emain(void* arg)
{
    unsigned short int T1, T2;
    unsigned short int tempx,temp , help, temp2, temp3, temp4, portwert, wert;
    unsigned short int i=0;

    #define HIGHBIT 11
    #define LOWBIT 9
    #define MASK 0x07


    // Mit den folgenden beiden Defines kann bestimmt werden welche Simulations-Tools verwendet werden.
    // Diese MUESSEN dann auch gestartet werden.
    // ######### IN DIESEM VERSUCH MUESSEN SIE OHNE DAS BANDMODELL ARBEITEN,             ##############
    // ######### da dieses sonst die Eingabe ueber das User-Interface "ueberschreibt".   ##############
    //INIT_BM_WITH_REGISTER_UI;		// Es werden beide Simulations-Tools (Bandmodell.exe und User_Interface.exe) verwendet
    INIT_REGISTER_UI_WITHOUT_BM		// Es wird nur das User-Interface zur Registerdarstellung (User_Interface.exe) verwendet.


    while(1) {

        SYNC_SIM;

        tempx = io_in16(IN1);		// Einlesen von Port 1

        tempx = tempx >> 4;	// So oft nach rechts shiften
                            // bis das Bit 4 an der Bitstelle 0 steht.

        T1 = tempx & 0x01;	// Zur Sicherheit alle Bits,
                            // bis auf Bit0 auf 0 setzen
                            // und das Ergebnis T1 zuweisen.
        /*	Das Bit für den Taster T1 ist nun eingelesen und
        die Variablen T1 hat genau den logischen Wert dieses
        Bits, d.h.
        T1 = 0 wenn Bit 4 = 0 , also wenn Taster T1 betätigt.
        T1 = 1 wenn Bit 4 = 1 , also wenn Taster T1 nicht betätigt.
        Für T2 machen wir nun das Gleiche.
        */
        tempx = in(IN1);		// Einlesen von Port 1

        tempx = tempx >> 5;	// So oft nach rechts shiften
                            // bis das Bit 5 an der Bitstelle 0 steht.

        T2 = tempx & 0x01;	// Alle Bits, bis auf Bit0 auf 0 setzen
                            // und das Ergebnis T2 zuweisen.


        //---------------- EINLESEN ENDE --------------------


        portwert = io_in16(DIR1);

        temp2 = HIGHBIT - LOWBIT +1;// mask anzahl als DEZ in temp2
        int j;
        for(j=0;j<temp2;j++){   // Erstellen des temp Bit Musters (z.B Bit 9-12 = 1)
            temp = temp | (1 << (LOWBIT+j));
        }

        wert = (portwert & temp) >> LOWBIT; // Seperieren der relevanten Bits + gnaz nach rechts schiften



        temp3=1;

        // Kreislauf der Bits (rechts herum)
        if(T1 == 1 && T2 == 0) {
                temp3 = temp3 << (temp2-1);             // Die zu verlierede stelle wird ermitteln
                temp4 = (wert & temp3);                 // temp4 speichert den wert der beim shiften verloren geht
                temp4 = temp4 >> (temp2-1);             // temp4 schiebt den wert auf die stelle die wegfällt

                wert = wert << 1;                       // das verschieben findet statt
                wert = wert | temp4;                    // der vorne rausgefallene wert wird hinten wieder dran gehangen.
                wert = wert << LOWBIT;                  // shiften auf richtige position
                wert = wert & temp;                     // Alle anderen stellen mit temp1 (maske an richtiger stelle) auf "0" setzt

        }

        // Kreislauf der Bits (links herum)
        else if(T1 == 0 && T2 == 1) {
                // ist hier immer die 0te               // Die zu verlieren stelle wird ermitteln
                temp4 = (wert & temp3);                 // temp4 speichert den wert der beim shiften verloren geht
                temp4 = temp4 << (temp2-1);             // temp4 schiebt den wert auf die stelle die wegfällt

                wert = wert >> 1;                       // das verschieben findet statt
                wert = wert | temp4;                    // der vorne rausgefallene wert wird hinten wieder dran gehangen.
                wert = wert << LOWBIT;                  // shiften auf richtige position
                wert = wert & temp;                     // Alle anderen stellen mit temp1 (maske an richtiger stelle) auf "0" setzt


        }

        io_out16(DIR1, wert);
        i++;
    }


    END;





}
#endif //V1_Aufgabe_3_loesung

