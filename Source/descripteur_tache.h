#ifndef _DESCRIPTEUR_TACHE_H	
#define	_DESCRIPTEUR_TACHE_H

#include "raccordeur.h"

/*!
 * Decrit une tache qui sera donnee a executer a une instance de la classe
 * Textureur a l'aide de la methode traiterTache(...).
 * 
 * Cette classe est plutot une "struct", elle ne contient aucune methodes et
 * tous ses attributs sont "public" et donc accessible par tout le monde.
 */
class DescripteurTache {
public:
  /*!
   * Fichier image d'entree du textureur.
   */
  const char* fichierImage;

  /*!
   * Faut-il utiliser un permuteur (classe Permuteur) ou choisir un nouveau bloc
   * au hasard a chaque fois (avec risque de reutiliser le meme trop souvent).
   */
  bool utiliserPermuteur;

  /*!
   * Faut-il essayer plusieurs blocs a chaque fois et choisir le meilleur ou
   * choisir le premier bloc que l'on a.
   */
  bool choisirMeilleurBloc;

  /*!
   * Boolean cache fucntion bestBlockIndex
   * Because everytime call bestBlockIndex its compare with all blocks
   * So we crate a 2d matrix to store distance between block A and block B
   * If exist just return distance
   * else calculate and save to matix
  */
  bool cacheBestBlock;

  /*!
   * we crate a 3d matrix to store best coupe between block A and block B
  */
  bool cacheBestCoupe;

  /*!
   * visualization
   * if set this true visualise image and wait for user
   * else just run the algorithm (for time testing)
  */
  bool visualization;

  /*!
   * Racine carre du nombre de blocs 
   */
  int racineNombreBlocs;

  /*!
   * Taille de la zone de recouvrement en pixels.
   */
  int recouvrement;

  /*!
   * Taille horizontale en pixels de l'image generee.
   */
  int largeurSortie;

  /*!
   * Taille verticale en pixels de l'image generee.
   */
  int hauteurSortie;

  /*!
   * Pointeur vers un objet implementant l'algorithme a utiliser pour calculer
   * la coupe a operer pour recoller deux blocs de l'image. Cet objet est
   * aussi responsable de produire le cout de racordement des deux blocs a
   * recoller (\see{Raccordeur#calculerRaccord}).
   */
  Raccordeur* raccordeur;
  
  /*!
   * Constructeur.
   * Comme il est la seule methode de la classe et est tres simple, on se permet
   * de le mettre directement dans le .h
   */
  DescripteurTache() :
    fichierImage(NULL), utiliserPermuteur(false), racineNombreBlocs(-1),
    recouvrement(-1), largeurSortie(-1), hauteurSortie(-1), raccordeur(NULL)
  {}
};

#endif	/* _DESCRIPTEUR_TACHE_H */

