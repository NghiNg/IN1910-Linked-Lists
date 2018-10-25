# project2_bdnguye_sigursor
**https://github.uio.no/IN1910/project2_bdnguye_sigursor**  
Besvarelse på gruppeprosjekt 2 i IN1910.

4.g - Pop quiz: I Josephus problem, for 68 menn og for hvert 7de mann drept, vil mann nr 68 være den siste som står igjen.

**Oppg. 3 - Store O "kalkulasjon".**

Vi gjør en enkel stor O- beregning av algoritmene våre for diverse funksjonaliteter.

ArrayList = AL    LinkedList = LL       k er en konstant        n er listelengden


    - get_element.
        AL:     Alt vi trenger å gjøre er å lese av et element i en liste.
                Dette er uavhengig av lengden på lista.
                O(n) = k

        LL:     Vi må iterere oss frem til et element.
                Dette er avhengig av hvor lang lista vår er.
                O(n) = n

    - insert_front.
        AL:     Vi må flytte alle verdiene i lista bortover.
                Dette er avhengig av listelengde.
                O(n) = n

        LL:     Vi lager en ny node og linker den til head.
                Dette er ikke avhengig av listelengde.
                O(n) = k

    - insert_back.
        AL:     I utgangspunktet er dette bare å gi en ny elementverdi, men noen
                ganger er vi nødt til å resize hele lista, så det går opp til en
                n-avhengig operasjon.
                O(n) = n

        LL:     Med "tail"-funksjonalitet i lista kan vi lett navigere oss til
                slutten og legge til en node der. Dette er da uavhengig av
                listelengde.
                O(n) = k

    - insert_middle.
        AL:     Vi må minst reallokere alle elementer etter den innstukne indeksen
                Dette er avhengig av listelengde.
                O(n) = n

        LL:     Vi må telle oss fram til riktig node og legge inn en ny node
                på den riktige plassen. Denne tellingen er avhengig av listelengden.
                O(n) = n

    - remove_front.
        AL:     Vi blir nødt til å flytte alle elementer i lista til en ny plass.
                Dette skalerer med listelenden.
                O(n) = n

        LL:     ALt vi trenger å gjøre er å fjerne en node og flytte "head".
                Dette avhenger ikke av listelengde.
                O(n) = k

    - remove_back.
        AL:     Vi sier at den viste datalengden er én mindre enn før.
                Dette er ikke avhengig av listelengden.
                O(n) = k

        LL:     Med "tail"-funksjonalitet kan vi lett navigere oss til slutten
                av lista og fjerne en node der. Dette blir da lengdeuavhengig.
                O(n) = k


    - remove_middle.
        AL:     Vi må igjen reallokere alle elementer etter den valgte indeksen.
                Dette avhenger av listelengde.
                O(n) = n

        LL:     Vi må telle oss fram til den ønskede noden og fjerne den.
                Denne tellingen er avhengig av listelengde.
                O(n) = n

    - print.    
        AL:     Vi leser gjennom lista og gjør et bestemmt antall  operasjoner per element.
                Dette er bare avhengig av listelengden.
                O(n) = n

        LL:     Vi itererer gjennom hele lenken og gjør et fast anntall operasjoner
                per node. Dette skalerer kun lineært med listelengden.
                O(n) = n
