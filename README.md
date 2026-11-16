# Éditeur C++ — première étape

## But de cette version

Cette version constitue un premier prototype d'interface Qt. Elle ouvre une fenêtre avec une zone d'édition au centre et une barre de statut qui affiche la ligne et la colonne du curseur. Elle ne gère pas encore les fichiers, la recherche/remplacement, la coloration syntaxique, les thèmes ou les curseurs multiples : ces fonctionnalités seront ajoutées après validation de cette base.

## Organisation des fichiers

```text
EditeurCpp/
├── CMakeLists.txt
├── README.md
└── src/
    ├── main.cpp
    ├── MainWindow.h
    ├── MainWindow.cpp
    ├── CodeEditor.h
    └── CodeEditor.cpp
```

- `CMakeLists.txt` décrit la construction du programme et indique à CMake d'utiliser Qt 6 Widgets. `CMAKE_AUTOMOC` permet à Qt de traiter les classes qui utilisent `Q_OBJECT`.
- `src/main.cpp` démarre Qt, crée la fenêtre principale, l'affiche et lance la boucle d'événements. La boucle permet à l'application de réagir aux clics et aux frappes clavier.
- `src/MainWindow.h` annonce la classe `MainWindow` et les objets qu'elle possède. Le pointeur `m_editor` est l'éditeur intégré; `m_statusLabel` est le texte de statut.
- `src/MainWindow.cpp` construit l'interface. `setCentralWidget` place l'éditeur au centre. La connexion (`connect`) met à jour la ligne et la colonne quand la position du curseur change.
- `src/CodeEditor.h` annonce notre composant d'édition spécialisé, dérivé de `QPlainTextEdit`.
- `src/CodeEditor.cpp` règle sa police à chasse fixe, affiche un texte indicatif et désactive le retour automatique à la ligne.

### Pourquoi un `.h` et un `.cpp` ?

Le fichier `.h` expose le contrat de la classe : son nom, ses méthodes et ses données membres. Le fichier `.cpp` contient les détails de réalisation. Cela évite de mélanger toute l'application dans un seul fichier et permet à deux personnes de travailler sur des composants distincts. Une classe qui utilise le système de signaux/slots de Qt porte `Q_OBJECT`; CMake doit alors activer `CMAKE_AUTOMOC`.

## Prérequis et compilation

Il faut CMake, un compilateur C++17 et Qt 6 avec le module Widgets. Depuis le dossier `EditeurCpp` :

```bash
cmake -S . -B build
cmake --build build
```

Puis lancer l'exécutable :

- Linux/macOS : `./build/EditeurCpp`
- Windows : `build/Debug/EditeurCpp.exe` ou le chemin d'exécutable généré par votre générateur CMake.

Si votre projet scolaire utilise Qt 5, il faudra remplacer `Qt6` par `Qt5` dans `CMakeLists.txt` et adapter la configuration selon votre installation. Cette version est configurée pour Qt 6.

## Ce que je peux expliquer au professeur

> « J'ai commencé par séparer l'application en deux responsabilités. `MainWindow` assemble l'interface et affiche l'état du curseur; `CodeEditor` configure la zone de saisie. `main.cpp` démarre l'application et CMake configure sa compilation. Le premier objectif est volontairement réduit : vérifier que la fenêtre et l'éditeur fonctionnent avant d'ajouter les opérations sur les fichiers et les fonctions avancées. »

Démonstration : lancer l'application, cliquer à différents endroits dans la zone de texte et montrer que l'indication de ligne/colonne se met à jour.

## Travail à deux avec GitHub

Convenez d'abord de la branche principale (`main`) et vérifiez que les deux machines peuvent compiler le projet. Une répartition possible après cette première base :

- Personne A : `MainWindow` et les actions de fenêtre.
- Personne B : `SearchReplaceBar`, dans ses propres fichiers `.h` et `.cpp`.
- Plus tard : intégrer `CppHighlighter` et le fichier original de déclarations en déplaçant progressivement les interfaces dans des en-têtes dédiés.

Ne modifiez pas en même temps le même fichier sans coordination. Pour la prochaine tâche, chacun peut créer une branche séparée :

```bash
git switch main
git pull
git switch -c feature/nom-de-la-tache
# modifier le code, puis compiler et tester
git add CMakeLists.txt README.md src/
git commit -m "Ajoute le prototype de la fenêtre principale"
git push -u origin feature/nom-de-la-tache
```

Remplacez le chemin de `git add` par les fichiers réellement modifiés. Ensuite, ouvrez une pull request GitHub, décrivez le changement et dites comment le tester. Le camarade relit la pull request avant fusion dans `main`.

> Note : si le dépôt existe déjà et contient des fichiers, copiez uniquement les fichiers du projet qui ne sont pas présents; ne remplacez pas les fichiers de votre camarade sans comparaison préalable.

## Étapes suivantes proposées

1. Vérifier et faire compiler ce prototype sur les deux ordinateurs.
2. Ajouter les actions « Nouveau », « Ouvrir » et « Enregistrer » dans `MainWindow`.
3. Ajouter les protections contre la perte de modifications non enregistrées.
4. Développer `SearchReplaceBar` et la connecter à `CodeEditor`.
5. Ajouter `CppHighlighter`, puis les fonctions avancées de recherche/sélection.

Chaque étape devrait avoir un objectif testable, un commit explicite et une courte description dans la pull request.
