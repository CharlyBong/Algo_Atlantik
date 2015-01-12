/**
 * \file Harbor.cpp
 * \brief Impl�mentation de la classe Harbor
 * \author Charles Bong.
 * \date 21 Novembre 2014
 */

#include "Harbor.h"

#define FILE "trafic.txt"
using namespace std;

Harbor* Harbor::_uniqueInstance = NULL;


/** \brief V�rifie la validit� des coordonn�es d'une case
 *
 * \param x int : Dimension x du port (10 par d�faut)
 * \param y int : Dimension y du port (10 par d�faut)
 * \author Charles Bong.
 */
Harbor::Harbor(int x, int y)
{
    _maxx = x;
    _maxy = y;
    srand(time(NULL));

    vector<int> listdock(2*_maxy) ;
    iota(listdock.begin(),listdock.end(),1);
    random_shuffle(listdock.begin(),listdock.end());

    vector<int>::const_iterator
        mit(listdock.begin()),
        mend(listdock.end());

    for(int i=0;i<_maxx;i++)
    {
        _dock[Cell(i,0)]    = new Dock(*mit);
        mit++;
        _dock[Cell(i,y-1)]  = new Dock(*mit);
        mit++;
    }
}

/** \brief Destructeur
 * \author Charles Bong.
 */
Harbor::~Harbor(){
}

/** \brief R�cup�rateur d'instance
 * \author Charles Bong.
 */
Harbor* Harbor::getInstance(){
    if(_uniqueInstance == NULL)
        _uniqueInstance = new Harbor();
    return _uniqueInstance;
}

/** \brief Destructeur d'instance
 * \author Charles Bong.
 */
void Harbor::destroy(){
    if(_uniqueInstance)
        delete _uniqueInstance;
}


/** \brief Insertion d'un bateau :
 *  Ajoute un Ship sur la grille, en le fessant entr�e pas les cases de d�part pr�-d�fini
 * \param bateau Ship* : bateau � faire rentr� dans le port
 * \return Cell : cellule d'arriv� ou la case (-1,-1) s'il n'y a pas de place en entr�e
 * \author Charles Bong.
 */
Cell Harbor::addShip(Ship* bateau){
    list<Cell> posinit = getInitialPositions();
    for (list<Cell>::iterator it = posinit.begin(); it != posinit.end(); it++ ){
        if(addShip(bateau,*it)==0) return *it;
    }
    ecrire(FILE,"ERR ADD : "+bateau->getNom());
    return Cell(-1,-1);
}

/** \brief Placement d'un bateau :
 *  Ajoute un Ship sur la grille sur la case donn�e
 * \param bateau Ship* : bateau � placer
 * \param position Cell : case d'arriv�
 * \return int : 0 pour une insertion r�ussi, -1 en cas d'erreur
 * \author Charles Bong.
 */
int Harbor::addShip(Ship* bateau,Cell position)
{
    if(_grid[position]==NULL){
        ecrire(FILE,"ADD : "+bateau->getNom());
        _grid[position]=bateau;
        return 0;
    }
    return -1;
}

/** \brief Placement d'un bateau :
 *  Ajoute un Ship sur la grille au cordonn�e fourni
 * \param bateau Ship* : bateau � placer
 * \param x int : cordonn�e x
 * \param y int : cordonn�e y
 * \return int : 0 pour une insertion r�ussi, -1 en cas d'erreur
 * \author Charles Bong.
 */
int Harbor::addShip(Ship* bateau,int x, int y)
{
    return addShip(bateau,Cell(x,y));
}

/** \brief R�cup�ration du bateau � l'emplacement donn�e:
 * \param x int : cordonn�e x
 * \param y int : cordonn�e y
 * \return Ship :
 * \author Charles Bong.
 */
Ship* Harbor::getShip(int x, int y)
{
     return _grid[Cell(x,y)];
}

/** \brief D�placement d'un bateau :
 *  transfert du bateau de la cellule c1 � c2
 * \param c1 Cell : Cordonn�e d'origine
 * \param c2 Cell : Cordonn�e d'arriv�
 * \return Cell : Cellule d'arriv� effective, ou la case (-1,-1) en cas d'erreur
 * \author Charles Bong.
 */
Cell Harbor::MoveTo(Cell c1, Cell c2)
{
    return MoveTo(c1._x,c1._y,c2._x,c2._y);
}

/** \brief D�placement d'un bateau :
 *  transfert du bateau d'une cellule � une autre, incluant les possibles collisions
 * \param c1 Cell : Cordonn�e d'origine (x1,y1)
 * \param c2 Cell : Cordonn�e d'arriv� (x2,y2)
 * \return Cell : Cellule d'arriv� effective, ou la case (-1,-1) en cas d'erreur
 * \author Charles Bong.
 */
Cell Harbor::MoveTo(int x1, int y1, int x2, int y2)
{
    if( verifcase(x1,y1)!=1 ) return (Cell(-1,-1)); // Erreur, pas de bateau ici

    if( verifcase(x2,y2)==1 ) // Si la case est d�j� occup� (Collision)
    {
        stringstream ss;
        ss << " ("<<x1<<","<<y1<<") to ("<<x2<<","<<y2<<") ";
        ecrire(FILE,"COLI : "+ss.str()+_grid[Cell(x1,y1)]->getNom() + " -> "+ _grid[Cell(x2,y2)]->getNom());
        if( collision(_grid[Cell(x1,y1)],_grid[Cell(x2,y2)]) == 1)
            _grid[Cell(x2,y2)] = NULL;
    }

    if( verifcase(x2,y2)==0 ) // Si la case est libre (D�placement)
    {
        _grid[Cell(x2,y2)] =  _grid[Cell(x1,y1)];
        _grid[Cell(x1,y1)] = NULL;
        stringstream ss;
        ss << " ("<<x1<<","<<y1<<") to ("<<x2<<","<<y2<<")";
        ecrire(FILE,"MOVE : "+_grid[Cell(x2,y2)]->getNom() + ss.str());
        return Cell(x2,y2);
    }

    return Cell(x1,y1);
}

/** \brief Suppression d'un bateau :
 *  D�truit la contenance d'une case
 * \param x int : Cordonn�e x
 * \param y int : Cordonn�e y
 * \author Charles Bong.
 */
void Harbor::Delete(int x, int y)
{
    ecrire(FILE,"BYE : "+_grid[Cell(x,y)]->getNom());
    _grid[Cell(x,y)] = NULL;
}

/** \brief G�n�re un num�ro de dock al�atoire
 * \param maxi int : nombre maximum de dock
 * \return int : num�ro du quai
 * \author Charles Bong.
 */
int Harbor::getDockaleat(int maxi)
{
    int nb;
    do
    {
        nb = rand()%(maxi);
    }while( finddock(nb) != Cell(-1,-1) );
    return nb;
}

/** \brief Affichage du port
 * \author Charles Bong.
 */
void Harbor::print()
{
    for(int i=0;i<_maxx;i++)
    {
        cout << _dock[Cell(i,0)]->_id << "\t|->";
        for(int j=0;j<_maxy;j++)
        {
            if(_grid[Cell(i,j)] == NULL) cout << "~";
                else cout << "O";
        }
        cout << "<-|\t" << _dock[Cell(i,_maxy-1)]->_id << endl;
    }
}

/** \brief R�cup�re les coordonn�es d'un quai
 * \param id int : Num�ro du quai
 * \return Cell : Cellule du quai, ou la case (-1,-1) en cas d'erreur
 * \author Charles Bong.
 */
Cell Harbor::finddock(int id){
    Dock* d;
    for(int i=0;i<_maxx;i++)
    {
        d = _dock[Cell(i,0)];
        if((d != NULL) && (d->_id == id))   return Cell(i,0);
        d = _dock[Cell(i,_maxy-1)];
        if((d != NULL) && (d->_id == id))   return Cell(i,_maxy-1);
    }
    return Cell(-1,-1);
}

/** \brief R�servation d'un quai :
 *  Permet de r�server un quai pour un Ship
 * \param id int : Num�ro du quai
 * \param bateau Ship* : Bateau demandant la r�servation
 * \return Cell : Cellule du quai, ou la case (-1,-1) en cas d'erreur
 * \author Charles Bong.
 */
int Harbor::resaDock(int id, Ship* bateau){
    Dock* d = _dock[finddock(id)];
    return d->reservation(bateau);
}

/** \brief R�servation d'un quai pour un bateau :
 *  r�serve un quai pour un bateau, s'il n'y a pas de place, v�rifie si un bateau est prioritaire sur un bateau d�j� gar�
 * \param bateau Ship* : bateau demandant une place
 * \return Cell : Cellule du quai r�serv�, ou la case (-1,-1) s'il n'y a pas de place
 * \author Charles Bong.
 */
Cell Harbor::getresaDock(Ship* bateau){
    Dock* d;
    // R�servation Classique
    for(int i=0;i<_maxx;i++)
    {
        d = _dock[Cell(i,0)];
        if(d->reservation(bateau)==0){
            stringstream ss;
            ss << d->_id;
            string t = "BIND : "+ (bateau->getNom()) +" ("+ ss.str() +")";
            ecrire(FILE,t);
            return Cell(i,0);
        }
        d = _dock[Cell(i,_maxy-1)];
        if(d->reservation(bateau)==0){
            stringstream ss;
            ss << d->_id;
            string t = "BIND : "+ (bateau->getNom()) +" ("+ ss.str() +")";
            ecrire(FILE,t);
            return Cell(i,_maxy-1);
        }

    }
    // Surr�servation
    for(int i=0;i<_maxx;i++)
    {
        d = _dock[Cell(i,0)];
        if(d->surreservation(bateau)==0){
            stringstream ss;
            ss << d->_id;
            string t = "SURB : "+ (bateau->getNom()) +" ("+ ss.str() +")";
            ecrire(FILE,t);
            return Cell(i,0);
        }
        d = _dock[Cell(i,_maxy-1)];
        if(d->surreservation(bateau)==0){
            stringstream ss;
            ss << d->_id;
            string t = "SURB : "+ (bateau->getNom()) +" ("+ ss.str() +")";
            ecrire(FILE,t);
            return Cell(i,_maxy-1);
        }

    }
    return Cell(-1,-1);
}

/** \brief R�cup�re le num�ro du quai r�server pour le bateau
 * \param bateau Ship* : bateau ayant fait la r�servation
 * \return int : id du quai, ou -1 s'il n'y a pas de quai r�server
 * \author Charles Bong.
 */
int Harbor::getidresa(Ship* bateau){
    Dock* d;
    for(int i=0;i<_maxx;i++)
    {
        d = _dock[Cell(i,0)];
        if((d != NULL) && (d->_bateau == bateau))   return d->_id;

        d = _dock[Cell(i,_maxy-1)];
        if((d != NULL) && (d->_bateau == bateau))   return d->_id;
    }
    return -1;
}

/** \brief R�cup�ration des entr�es du port :
 *  G�n�ration d'une liste de point d'entr�e du port
 * \return list<Cell> : liste de cellule de point d'entr�e
 * \author Charles Bong.
 */
list<Cell> Harbor::getInitialPositions(){
    list<Cell> posinit;
    int dim = (int) _maxy/2;
    posinit.push_back(Cell(0,dim-1));
    posinit.push_back(Cell(0,dim));
    return posinit;
}

/** \brief �criture dans le fichier de log
 * \param file string : Chemin d'acc�s du fichier de log
 * \param text string : message � �crire
 * \author Charles Bong.
 */
void Harbor::ecrire(string file,string text){
    ofstream fichier(file.c_str(), ios::app);
    if(fichier){
        time_t t = time(0);
        struct tm  tstruct = *localtime(&t);
        char       temp[80];
        strftime(temp, sizeof(temp), "%X", &tstruct);
        fichier << "TIME : " << temp << endl;
        fichier << text << endl;
        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

/** \brief Gestion de collision entre deux bateau
 * \param s1 Ship* : bateau qui souhaite se d�placer
 * \param s1 Ship* : bateau sur le chemin de s1
 * \return int : 0 si s1 fait demi-tour, 1 si s1 �crase s2
 * \author Charles Bong.
 */
int Harbor::collision(Ship* s1, Ship* s2){
    if(s1->getHullSolidity() > s2->getHullSolidity()){
        // S1 > S2 -> destruction de S2
        ecrire(FILE,"KILL : "+s1->getNom() + " -> "+ s2->getNom());
        s2->~Ship();
        return 1;
    }
    // else Don't MOVE !
    ecrire(FILE,"OMFG : "+s1->getNom() + " <- "+ s2->getNom());
    return 0;
}

/** \brief V�rifie la validit� des coordonn�es d'une case
 *
 * \param x int : Coordonn�e x de la case
 * \param y int : Coordonn�e y de la case
 * \return int : 0 si la case et valide et libre, sinon un code d'erreur
 * \author Charles Bong.
 */
int Harbor::verifcase(int x, int y){
    if((x < 0)||(x > _maxx)) return -1;     // coordonn�e x inexistante
    if((y < 0)||(y > _maxy)) return -2;     // coordonn�e y inexistante
    if( _grid[Cell(x,y)]!= NULL ) return 1; // case d�j� occup�
                                            // else
    return 0;                               // case valide
}
