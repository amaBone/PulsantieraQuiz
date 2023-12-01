# PulsantieraQuiz
Pulsantiera per gioco a quiz in arduino

Realizzata per un gioco a quiz per un evento locale.

consiste in 1 arduino mega
1 cassetta per esterno liscia in grado di contenere arduino e i collegamenti
8 led
resistori vari
2 pushbutton 1 per il reset uno per lo start del gioco (lo start riavvia il gioco ma spegne il controllo del giocatore precedente con risposta errata)
1 buzzer 
8 cassette lisce per esterno con alloggio per un pulsante (domestico)
1 pulsante per cassetta
1 led per cassetta

cavetteria di collegamento fissa,(si potrebbe utilizzare uno spinotto 3-4 poli)
1 alimentatore 5v

alla pressione di start, i led sulla postazione di comando si accendono in sequenza, i led si ripetono sulle pulsantiere dei giocatori
il buzzer emette un suono

vengono letti 1 per volta i pulsanti alla ricerca di continuita', nel caso 2 pulsanti vengano premuti contemporaneamente, ha precedenza il pulsante controllato per prima (1 ~ 8, 1 ha precedenza su 8)
il buzzer suona, il led del pulsante premuto si accende
il giocatore risponde alla domanda, se errata, si preme start sul controllore, il buzzer suona e il gioco riparte escludendo il giocatore che ha fornito la risposta errata in precedenza.

alla pressione del tasto reset, i giocatori esclusi vengono riabilitati, i led si accendono in sequenza, il buzzer suona, il gioco riparte.
per qualsiasi informazione o chiarimento potete contattarmi a bada.nino95@gmail.com





