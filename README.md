# My Paint - Picture Editor

## Description
**My Paint** est un logiciel de dessin interactif inspiré de programmes comme GIMP ou Photoshop. Le but principal de ce projet est de développer une interface graphique utilisateur (GUI) en utilisant **CSFML**. Ce logiciel inclut des outils simples tels qu'un crayon et une gomme, ainsi que des fonctionnalités avancées comme la gestion des couches et des formes.

---

## Fonctionnalités Principales

### Obligatoires
- **Fenêtre GUI complète :**  
  Fenêtre minimisable, agrandissable et fermable.
- **Outils de base :**  
  - Crayon (pencil) avec réglage de l'épaisseur de la ligne.
  - Gomme (eraser) avec réglage de la forme (cercle ou carré) et de la taille.
- **Barre de menus :**  
  - **File :**
    - New file, Open file, Save file.
  - **Edit :**
    - Sélection des outils (pencil et eraser).
  - **Help :**
    - À propos (affiche votre login).
    - Aide (explication sur l'utilisation du logiciel).
- **Dessiner avec la souris.**
- **Enregistrement d'image :**  
  Par défaut au format `.jpg`.
- **Gestion des états des boutons :**  
  HOVER, PRESSED, CLICKED.

### Optionnelles
- **Boîte de dialogue pour le nom de fichier.**
- **Gestion des calques :**  
  Ajout, suppression, gestion indépendante.
- **Palette de couleurs :**  
  Permet de choisir la couleur du crayon.
- **Sauvegarde dans plusieurs formats :**  
  `.bmp`, `.png`, etc.
- **Ajout de formes simples :**  
  Cercle, rectangle.
- **Outils supplémentaires :**  
  - Zoom sur l'image.
  - Outil de sélection rectangulaire.
  - Copier/Couper/Coller des sélections sur une image ou un calque.

### Bonus
- Gestion des masques de calques.
- Importation d'images.
- Gestion avancée des pinceaux pour le crayon et la gomme.
- Transformations : translation, rotation.
- Annulation et rétablissement (Undo/Redo).

---

## Compilation et Exécution

### 1. Compiler le projet
Le projet utilise un **Makefile** pour automatiser la compilation.

- Pour compiler le projet, exécutez :
  ```bash
  make
