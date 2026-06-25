# 🚀 C-Projects: Architecture Logic & Gestion de Mémoire

Bienvenue dans mon dépôt de projets en langage C. Ce répertoire centralise mes travaux pratiques axés sur l'implémentation d'algorithmes, de structures de données
et la manipulation de bas niveau.

## 📌 Déclaration d'Objectif Académique
Au cours de mon parcours académique initial, le cursus universitaire était principalement orienté vers les langages de haut niveau et le développement d'applications. Consciente que la maîtrise du langage C et la gestion rigoureuse de la mémoire sont des piliers fondamentaux de l'ingénierierie logicielle, j'ai développé ces projets de manière **autonome**. 

Ces travaux démontrent ma capacité d'auto-apprentissage (*self-study*) et ma solide compréhension des concepts critiques exigés dans les cycles supérieurs (L2/L3/Master) en France, tels que :
* **Allocation Dynamique de Mémoire :** Utilisation avancée de `malloc`, `calloc` et `free` dans le Tas (*Heap*).
* **Pointeurs et Structures :** Manipulation de pointeurs simples, doubles, et de structures de données auto-référencées.
* **Optimisation et Robustesse :** Analyse et élimination systématique des fuites de mémoire (*Memory Leaks*).

---

## 📊 Sommaire des Projets (Portfolio)

### 📂 01. Analyseur Statistique de Données (*Analisador Estatístico*)
* **Concepts Clés :** Tableaux dynamiques, manipulation de pointeurs, algorithmes de tri et calculs statistiques.
* **Description :** Un outil en ligne de commande conçu pour traiter des flux de données numériques, calculer des métriques statistiques clés (moyenne, médiane, variance) et optimiser la recherche d'éléments en mémoire à l'aide de pointeurs.

### 📂 02. Tri Oncologique Clinique (*Triagem Oncológica*)
* **Concepts Clés :** Structures de données conditionnelles, files d'attente à priorités, logique booléenne de bas niveau.
* **Description :** Algorithme simulant un système de tri médical pour l'oncologie. Il classe dynamiquement la priorité des patients en fonction de variables cliniques, optimisant le temps de réponse et la structure des données en mémoire RAM pour des environnements critiques.

### 📂 03. Gestionnaire de Playlist Musicale (*Gestion de Playlist*)
* **Concepts Clés :** Liste chaînée doublement dynamique (*Doubly Linked List*), chirurgie de pointeurs (`suivant` / `précédent`), libération séquentielle.
* **Description :** Moteur complet de file d'attente musicale (style Spotify) fonctionnant entièrement sur le *Heap*. Permet l'insertion, la recherche et la suppression chirurgicale de nœuds au milieu da la liste en reconnectant les adresses physiques, se fermant avec un rapport de 0 fuite de mémoire (Garanti de style Valgrind).

---

## 🛠️ Environnement de Développement
* **Compilateur :** GCC 15.2
* **Normes Académiques :** Compilation stricte avec les drapeaux `-Wall -Wextra -g` pour assurer un code propre et hautement standardisé.
