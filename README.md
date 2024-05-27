# Catanus Chess

## Introduction

Are you tired of the same old game of chess? Want something new, fresh, and exciting? Look no further than Catanus Chess! This innovative twist on the classic game of chess brings resource management and strategy to the forefront, making each move a crucial decision.

## Overview
Catanus Chess is played by 2-4 players, each vying for supremacy on the board. The goal is simple: be the last player with their king standing. But achieving this goal requires cunning, resource management, and strategic thinking.

Recommended: 2 players (for now)

## Setup

Board: The board consists of tiles, each marked with a number and a resource type.

Pieces: Each player starts with a set of pieces: pawn, knight, bishop, rook, and king.

Resources: Players gather resources (water, food, weapon, stone) based on the numbers rolled on the dice.

## Gameplay

Roll the Dice: Before each turn, players roll the dice. The number rolled determines which tiles produce resources.

Resource Management: Use gathered resources to move and capture pieces. Different pieces require different combinations of resources.

Pawn: Water + Food

Knight: Water + Food + Weapon

Bishop: Water + Food + Weapon

Rook: Water + Food + Weapon + Stone

King: Water + Food + Stone

Movement: Pieces can move to any empty square on the board, provided the player has the necessary resources. To capture an opponent's piece, resources for both moving and capturing are required.

## Special Rules:

Pawn: Does not promote and captures vertically.

No Castling: Traditional castling is not allowed.

Piece Movement: Every piece can jump over any other piece.

## Strategy

Resource Allocation: Decide whether to gather resources for more powerful pieces or maintain a balanced army.

Positioning: Utilize the unique movement abilities of each piece to outmaneuver opponents and control key areas of the board.

Timing: Know when to strike and when to consolidate your defenses, as resources can be scarce.

Adaptability: Be prepared to adjust your strategy based on dice rolls and opponent movements.

## Conclusion

Catanus Chess breathes new life into the timeless game of chess, offering a dynamic and engaging experience for players of all skill levels. Are you ready to conquer the board and emerge victorious? Gather your resources, plot your moves, and claim victory in Catanus Chess!

Cerinte:
### Cerințe modele de limbaj la nivel de semestru
- [ ] minim o funcționalitate majoritar doar cu LLM
- [ ] minim 2-3 funcționalități ~50% voi, ~50% LLM-ul
- [ ] minim 2-3 funcționalități suficient de complicate pe care un LLM nu le poate implementa

### Tema 0

- [ ] Nume proiect (poate fi schimbat ulterior)
- [ ] Scurtă descriere a temei alese, ce v-ați propus să implementați

## Tema 1

#### Cerințe
- [ ] definirea a minim **3-4 clase** folosind compunere cu clasele definite de voi
- [ ] constructori de inițializare
- [ ] pentru o aceeași (singură) clasă: constructor de copiere, `operator=` de copiere, destructor
<!-- - [ ] pentru o altă clasă: constructor de mutare, `operator=` de mutare, destructor -->
<!-- - [ ] pentru o altă clasă: toate cele 5 funcții membru speciale -->
- [ ] `operator<<` pentru toate clasele pentru afișare (std::ostream)
- [ ] cât mai multe `const` (unde este cazul)
- [ ] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe
  - nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
- [ ] scenariu de utilizare a claselor definite:
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [ ] tag de `git`: de exemplu `v0.1`
- [ ] serviciu de integrare continuă (CI); exemplu: GitHub Actions

## Tema 2

#### Cerințe
- [ ] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [ ] moșteniri:
  - minim o clasă de bază și **3 clase derivate**
  - ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită
  - [ ] clasă cu atribut de tip pointer la o clasă de bază cu derivate
  - [ ] funcții virtuale (pure) apelate prin pointeri de bază din clasa care conține atributul de tip pointer de bază
    - minim o funcție virtuală va fi **specifică temei** (e.g. nu simple citiri/afișări)
    - constructori virtuali (clone): sunt necesari, dar nu se consideră funcții specifice temei
  - [ ] apelarea constructorului din clasa de bază din constructori din derivate
  - [ ] smart pointers (recomandat, opțional)
  - [ ] `dynamic_cast`/`std::dynamic_pointer_cast` pentru downcast cu sens
- [ ] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
- [ ] excepții
  - [ ] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim **3** clase pentru erori specifice
  - [ ] utilizare cu sens: de exemplu, `throw` în constructor (sau funcție care întoarce un obiect), `try`/`catch` în `main`
- [ ] funcții și atribute `static`
- [ ] STL
- [ ] cât mai multe `const`
- [ ] la sfârșit: commit separat cu adăugarea unei noi clase derivate fără a modifica restul codului, **pe lângă cele 3 derivate deja adăugate**
  - noua derivată nu poate fi una existentă care a fost ștearsă și adăugată din nou
- [ ] tag de `git`: de exemplu `v0.2`

## Tema 3

#### Cerințe
- [ ] 2 șabloane de proiectare (design patterns)
- [ ] o clasă șablon cu sens; minim **2 instanțieri**
  - [ ] preferabil și o funcție șablon (template) cu sens; minim 2 instanțieri
<!-- - [ ] o specializare pe funcție/clasă șablon -->
- [ ] tag de `git`: de exemplu `v0.3` sau `v1.0`

