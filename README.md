Hotellivarauksen ohjelman kuvaus

Johdanto

Tämä ohjelma on yksinkertainen hotellivarauksen hallintaohjelma, joka toimii komentorivillä. Sen tarkoituksena on simuloida hotellin huoneiden varausta, vapauttamista ja huoneiden tietojen hallintaa. Ohjelma on kirjoitettu C++ -kielellä ja se tallentaa huoneiden tiedot tiedostoon, jotta varaukset säilyvät ohjelman sulkemisen ja uudelleenkäynnistyksen jälkeen.

Ohjelmassa on käytössä kaksi huonetyyppiä: yhden hengen huoneet ja kahden hengen huoneet. Huoneiden määrä valitaan satunnaisesti ohjelman alussa, mutta kokonaismäärä on aina parillinen, jotta huoneet voidaan jakaa tasan kummallekin tyypille. Ohjelma tukee myös satunnaisia alennuksia huoneiden hinnoista, mikä tekee simulaatiosta realistisemman.

Ohjelman rakenne:

Huoneiden rakenne

Jokainen huone mallinnetaan Room-rakenteella, joka sisältää seuraavat tiedot:

id: huoneen numero

capacity: huoneen kapasiteetti (1 tai 2 henkilöä)

basePrice: huoneen perushinta per yö (100 EUR yhdelle, 150 EUR kahdelle)

occupied: tieto siitä, onko huone varattu (true) vai vapaa (false)

discount: huoneen alennusprosentti (0%, 10%, 20% tai 30%)

Lisäksi rakenteessa on funktio finalPrice(), joka laskee huoneen lopullisen hinnan ottaen alennuksen huomioon. Tämä mahdollistaa sen, että huoneen hinta voidaan näyttää tai käyttää varauksen yhteydessä automaattisesti.



Tiedostojen käyttö

Ohjelma käyttää tiedostoa rooms.txt huoneiden tietojen tallentamiseen ja lataamiseen.

Tallennus: jokaisen toimenpiteen jälkeen (varaus, varauksen poistaminen, huoneiden näyttäminen) huoneiden tila tallennetaan tiedostoon. Näin varaukset säilyvät myös ohjelman uudelleenkäynnistyksen jälkeen.

Lataus: ohjelman käynnistyessä se yrittää ladata huoneet tiedostosta. Jos tiedostoa ei löydy, ohjelma luo huoneet satunnaisesti ja tallentaa ne tiedostoon ensimmäistä kertaa.



Huoneiden generointi

Huoneiden generointi tapahtuu satunnaisesti seuraavasti:

Ohjelma arpoo huoneiden määrän väliltä 40–300, ja määrän on oltava parillinen.

Ensimmäinen puoli huoneista on yhden hengen huoneita.

Toinen puoli huoneista on kahden hengen huoneita.

Jokaiselle huoneelle annetaan satunnainen alennus 0%, 10%, 20% tai 30%.

Huoneiden generointi varmistaa, että ohjelma simuloi realistisesti hotellin eri huonetyyppejä ja erilaisia hintoja.



Käyttöliittymä

Ohjelma toimii komentoriviltä ja tarjoaa yksinkertaisen valikon:

Näytä kaikki huoneet

Näytä vapaat huoneet

Varaa huone

Poista varaus

Lopeta ohjelma

Käyttäjä syöttää valikon numeron, jonka mukaan ohjelma suorittaa toimenpiteen. Varausten tekeminen ja poistaminen päivittävät huoneiden tilan ja tallentavat muutokset tiedostoon.

Ohjelma näyttää kunkin huoneen tiedot: huoneen numero, kapasiteetti, perushinta, mahdollinen alennus sekä varaustilanne (vapaa/varattu).



Yhteenveto:

Tämä ohjelma tarjoaa yksinkertaisen ja selkeän simulaation hotellihuoneiden hallinnasta. Ohjelma tukee:

satunnaista huoneiden määrää,

alennusten käyttöä,

huoneiden varaamista ja varausten poistamista,

tietojen tallentamista tiedostoon ja lataamista tiedostosta.

Ohjelma sopii harjoitteluprojektiksi C++ -ohjelmoinnin opiskeluun, erityisesti rakenteiden, vektoreiden, tiedostojen käsittelyn ja perustoiminnallisten komentorivikäyttöliittymien oppimiseen.

Kokonaisuudessaan ohjelma tarjoaa toimivan, käyttäjäystävällisen ja toistettavan tavan hallita hotellihuoneiden varauksia, mikä tekee siitä hyvän harjoitteluprojektin sekä ohjelmoinnin että ohjelmasuunnittelun perusteiden oppimiseen.
