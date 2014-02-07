Elemente de Grafica pe Calculator - Tema 1
Geometry Wars

Nume: Ciobanu Alin Emanuel
Grupa: 332 CC

Curpins
1. Cerinta
2. Utilizare
3. Implementare
4. Testare
5. Probleme Aparute
6. Continutul Arhivei
7. Functionalitati


1. Cerinta
Tema consta in realizarea unui joc de tip Geometry Wars in care o nava controlata de un jucator trebuie sa 
distruga inamicii care vin spre el. Are la dipozitie un burghiu cu care ii poate ataca.

2. Utilizare

2.1 Consola si fisiere
Executabilul nu primeste parametri la consola.
Nu am folosit fisiere de intrare.

2.2 Input tastatura
Tasta sageata sus se foloseste pentru a muta jucatorul.
Tasta sageasta stanga, respectiv dreapta se folosesc pentru a roti jucatorul.
Tasta SPACE se foloseste pentru a activa burghiul.
Tasta ESC inchide programul.
Nicio alta tasta nu mai este folosita.

3 Implementare
IDE: Visual Studio 2012
Sistem de operare: Windows 7 Ultimare Edition (64 bit)
Framework-ul folosit a fost cel din laborator. Singura modificare a fost adaugarea de listenere 
pentru a asculta la ridicarea unei taste.

3.1 Clase si dependentele dintre ele
Clasele adaugate fata de cele deja existente au fost cele pentru Enemy, Player si o clasa pentru 
nivele (Level).
Din clasa Enemy au fost derivate 4 clase pentru cele 4 tipuri de inamici. Clasele Enemy comunica 
cu clasa Player pentru ca un inamic sa stie pozitia la care se afla player-ul.
Metodele cele mai importante pentru Player sunt move si rotate care il ajuta sa se miste.
Enemy reuseste sa se mute (in diferite moduri) cu ajutorul move. Doi dintre inamici isi schimba directia 
random atunci cand se lovesc de zid, unul urmareste jucatorul, iar unul se isi seteaza directia spre 
jucator atunci cand loveste un zid.

4. Testare
Tema a fost testata in Visual Studio. 

5. Probleme aparute
Principalele probleme aparute au fost la comunicarea intre clase in C++ si, in general, cu limbajul (nu il stiu 
foarte bine; e primul proiect pe care il fac in C++).

6. Continutul arhivei

³   lab2.sln
³   README.txt
³   
----Debug
³       freeglut.dll
³       
----lab2
    ³   Cerc.cpp
    ³   Cerc.h
    ³   Enemy.cpp
    ³   Enemy.h
    ³   Enemy2Patrate.cpp
    ³   Enemy2Patrate.h
    ³   Enemy4Triunghiuri.cpp
    ³   Enemy4Triunghiuri.h
    ³   EnemyPatratFace.cpp
    ³   EnemyPatratFace.h
    ³   EnemyPatratVerde.cpp
    ³   EnemyPatratVerde.h
    ³   lab2.vcxproj
    ³   lab2.vcxproj.filters
    ³   Level.cpp
    ³   Level.h
    ³   main.cpp
    ³   Player.cpp
    ³   Player.h
    ³   
    ----Debug
    ³       lab2.Build.CppClean.log
    ³       lab2.log
    ³       
    ----dependente
    ³       freeglut.dll
    ³       freeglut.h
    ³       freeglut.lib
    ³       freeglut_ext.h
    ³       freeglut_std.h
    ³       glut.h
    ³       Readme_freeglut.txt
    ³       
    ----Framework
            Circle2D.h
            Color.h
            DrawingWindow.cpp
            DrawingWindow.h
            Line2D.h
            Object2D.h
            Point2D.h
            Point3D.h
            Polygon2D.h
            Rectangle2d.h
            Text.h
            Transform2D.cpp
            Transform2D.h
            Visual2D.cpp
            Visual2D.h
            

7. Functionalitati
Functionalitati Standard (ca in enunt):
	miscare player
	rotire player
	coliziune cu zidurile (marginile spatiului de joc)
Functionalitati Bonus:
	mai multe nivele
	inamici care se indreapta catre jucator
	ascultarea pe mai multe taste deodata