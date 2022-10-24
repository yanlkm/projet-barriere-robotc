/*===============================================================
 Nom du fichier : Barriere_V6.c
 Auteurs : Yan Marcel Ferel LIKEME & Otmane BENSLIMANE
 Date de création : Février 2020
 Version : V_7 (definitive)
 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 Description :
 Il s'agit d'un programme permettant de faire fonctionner une barriere lorsque ses capteurs ultrasons detectent un objet
 à une distance maximale de 15cm.
 Une fois le programme lancé, il faut le mettre en mode "fonctionnement", celui-ci possède deux sous-modes : libre et protégé.
 Lorsque le mode libre est enclenché, si le premier capteur ultrason détecte un objet à moins de 15 cm,
 automatiquement le moteur de la barriere tourne à 90° à 10% de sa puissance maximale vers le haut,
 si l'objet n'est plus détecté par les DEUX capteurs ultrasons de la barrière à moins de 15cm,
 le moteur tourne à -90° à 10% de sa puissance maximale  pour revenir à sa position initiale.
 En mode protégé, lorsque le premier capteur detecte un objet a moins de 15cm, un code secret est demandé via l'écran,
 si le code est bon, la barrière fonctionne comme en mode libre, si le code saisi est incorrect,
 la barrière ne fonctionne pas et le bon code est demandé via l'écran.
------------------------------------------------------------
 A noter :
 -Le premier signal sonore annonce le lancement du programme
 -Les autres signaux sonores informent le passage d'un mode à un autre

 Manuel d'utilisation avec la brique Lego EV3:
 Lorsque le programme est lancé, un message de bienvenue s'affiche à l'écran;
 -Pour mettre la barrière en mode "fonctionnement" : appuyer SIMULTANEMENT le bouton Droit et le bouton Gauche de la brique Lego
 -Pour  activer le mode libre de la barrière : appuyer le bouton Gauche de la brique Lego après avoir lancé le "Fonctionnement"
 -Pour activer le mode protégé de la barrière : appuyer le bouton Droit de la brique Lego après avoir lancé le "Fonctionnement"
 -Pour quitter le mode protégé vers le mode libre : appuyer simultanément sur les boutons Bas et Droit de la brique
 -Le code demandé dans le mode protégé est le suivant : Boutons Droit, Droit, Gauche, Gauche, Haut (successivement).
  ATTENTION : une seule erreur vous fera recommencer la saisie du code à zéro
 -Pour quitter le mode "Fonctionnement" : appuyer simultanément le bouton Haut et le bouton Bas de la brique.
===============================================================*/
//fonctions sonores signalant les changements de modes
void son1()
{
								setSoundVolume(1);
								playTone(1251, 14); while(bSoundActive){}
								playTone(1188, 14); while(bSoundActive){}
								playTone(1054, 14); while(bSoundActive){}
}
void son2()
{
								setSoundVolume(1);
								playTone(1251, 14); while(bSoundActive){}
								playTone(1188, 14); while(bSoundActive){}
								playTone(1054, 14); while(bSoundActive){}
}
void son3()
{

								setSoundVolume(1);
								playTone(1251, 14); while(bSoundActive){}

}

void son4()
{
								setSoundVolume(1);
								playTone(1401, 83); while(bSoundActive){}

}

task main()
{
//déclaration des variables du programme qui sont toutes des entiers
	int mode=0;
	int step=0;
	int son=0;
	int Son=0;
	int SON=0;
	int SoN=0;

				//fonction qui joue 4 notes au lancement du programme
				setSoundVolume(1);//Règle le volume à 1%
				playTone(695, 14); while(bSoundActive){}
				playTone(695, 14); while(bSoundActive){}
				playTone(695, 14); while(bSoundActive){}
				playTone(929, 83); while(bSoundActive){}

	while (getButtonPress(buttonLeft)!=true || getButtonPress(buttonRight)!=true)
/*affiche un message à l'écran tant les boutons Gauche et Droit de
la brique ne sont pas appuyés simultanément*/

{
//affiche en grand et au centre le message "Bienvenue sur Barriere Automatix" à l'écran
				displayCenteredBigTextLine(2,"Bienvenue ");
				displayCenteredBigTextLine(5,"sur ");
				displayCenteredBigTextLine(7,"Barriere ");
				displayCenteredBigTextLine(10,"Automatix ");

}

			eraseDisplay();//efface le contenu affiché à l'écran
			sleep(1000);//Attente de duree 1000 ms (millisecondes)


	while (!(getButtonPress(buttonUp)==1 && getButtonPress(buttonDown)==1) )
/*effectue le mode "fonctionnment" tant les boutons Haut et Bas de
la brique ne sont pas appuyés simultanément*/

{

	displayCenteredBigTextLine(5," Fonctionnement");//affiche en grand et au centre le message "Fonctionnement"

            if( getButtonPress(buttonRight)==true)//si le bouton Droit de la brique est appuyé
	    	  {
						mode=1;//la variable mode prend la valeur 1
              }
			if (getButtonPress(buttonLeft)==true)//si le bouton Gauche de la brique est appuyé
              {
						mode=2;//la variable mode prend la valeur 2
              }


				while (mode==1)//tant que la variable mode a pour valeur 1
				{
						//mode libre
									SensorType[S1] = sensorEV3_Ultrasonic;//Initialisation : un capteur ultrason est connecté sur l'entrée 1
									SensorType[S2] = sensorEV3_Ultrasonic;//Initialisation : un capteur ultrason est connecté sur l'entrée 2

										if (son==0)//si la variable son a pour valeur 0
												{
													son1();//faire jouer la fonction son1
													son=1;//la variable prend la vaeur 1
											  }
									displayCenteredBigTextLine(5," Mode Libre");//affiche en grand et au centre le message "Mode Libre"



									if (getUSDistance(S1)<15)//si l'obstacle est à moins de 15cm du capteur branché à l'entrée 1
										{
											setMotorTarget(motorA, 90, 10);//faire tourner le moteurA à 90° de sa position courante à 10% de sa puissance maximale
											sleep(2000);//Attente de duree 2000 ms (millisecondes)
										}
											if (SON==0)//si la variable SON a pour valeur 0
												{
													son3();//faire jouer la fonction son3
													SON=1;//la variable prend la vaeur 1
											  }
									if (getUSDistance(S2)>15 && getUSDistance(S1)>15 )//si l'obstacle est à plus de 15cm des capteurs branchés aux entrées 1 et 2
										{
											setMotorTarget(motorA, 0, 10);//laisser le moteurA immobile
											sleep(1000);//Attente de duree 1000 ms (millisecondes)
										}

									if (getButtonPress(buttonLeft)==true)//si le bouton Gauche de la brique est appuyé
										{
											mode=2;//la variable mode prend la valeur 2 (on sort du mode libre)
										}
				}

				while (mode==2)//tant que la valeur de la variable mode est 2
		  {						    SensorType[S1] = sensorEV3_Ultrasonic;//Initialisation : un capteur ultrason est connecté sur l'entrée 1
									SensorType[S2] = sensorEV3_Ultrasonic;//Initialisation : un capteur ultrason est connecté sur l'entrée 2

							 if (Son==0)//si la valeur de la variable Son est 0
									{
										son2();//faire jouer la fonction son2
										Son=1;//la variable prend la valeur 1
								  }

						displayCenteredBigTextLine(5," Mode Protege");//affiche en grand et au centre le message "Mode Protege"


								while (step!=5 && getUSDistance(S1)<15 )//tant que la valeur de la variable step est différent de 5 et l'obstacle est à moins de 15cm du capteur S1

								{       if (getUSDistance(S1)<15)//si l'obstacle est à moins de 15cm du capteur S1
											{
											    eraseDisplay();
												displayCenteredBigTextLine(8," Saisir le code ");//affiche en grand et au centre le message "Saisir le code"
											}

												if (step==0 && getButtonPress(buttonRight)==1)//si la valeur de step est 0 et que le bouton Droit est appuyé
												{
															step=1;//step prend la valeur 1
															eraseDisplay();
															displayCenteredBigTextLine(8," code %d ",step);//affiche en grand et au centre le message "code (valeur de step)"
															sleep(1000);
												}
												if (step==4 && getButtonPress(buttonUp)==1)//si la valeur de step est 4 et que le bouton Haut est appuyé
												{
															step=5;//step prend la valeur 5
															eraseDisplay();
															displayCenteredBigTextLine(8," code %d ",step);//affiche en grand et au centre le message "code (valeur de step)"
															sleep(1000);
												}
												if (step==1 && getButtonPress(buttonRight)==1)//si la valeur de step est 1 et que le bouton Droit est appuyé
												{
													    step=2;//step prend la valeur 2
															eraseDisplay();
															displayCenteredBigTextLine(8," code %d ",step);//affiche en grand et au centre le message "code (valeur de step)"
															sleep(1000);


												}
												if (step==2 && getButtonPress(buttonLeft)==1)//si la valeur de step est 2 et que le bouton Gauche est appuyé
												{
															step=3;//step prend la valeur 3
															eraseDisplay();
															displayCenteredBigTextLine(8," code %d ",step);//affiche en grand et au centre le message "code (valeur de step)"
															sleep(1000);
												}
												if (step==3 && getButtonPress(buttonLeft)==1)//si la valeur de step est 3 et que le bouton Gauche est appuyé
												{
															step=4;//step prend la valeur 4
															eraseDisplay();
															displayCenteredBigTextLine(8," code %d ",step);//affiche en grand et au centre le message "code (valeur de step)"
															sleep(1000);
												}


															if  (step==0 && (getButtonPress(buttonLeft)==1||getButtonPress(buttonUp)==1|| getButtonPress(buttonDown)==1 ))// si la valeur de step est 0 et que soit le bouton Haut,Gauche ou Bas est appuyé
																	{
																	step=0;//step prend la valeur 0
																	displayCenteredBigTextLine(8,"code incorrect ");
																	eraseDisplay();
																	sleep(750);
																	}
															if (step==1 && (getButtonPress(buttonLeft)==1||getButtonPress(buttonUp)==1|| getButtonPress(buttonDown)==1))// si la valeur de step est 1 et que soit le bouton Haut,Gauche ou Bas est appuyé

																{
																step=0;//step prend la valeur 0
																displayCenteredBigTextLine(8," code incorrect ");
																eraseDisplay();
																sleep(750);
																}
															if (step==2 &&(getButtonPress(buttonDown)==1||getButtonPress(buttonUp)==1||getButtonPress(buttonRight)==1))// si la valeur de step est 2 et que soit le bouton Haut,Droit ou Bas est appuyé

																{
																step=0;//step prend la valeur 0
																displayCenteredBigTextLine(8,"  code incorrect ");
																eraseDisplay();
																sleep(750);
																}
															if (step==3 &&(getButtonPress(buttonDown)==1||getButtonPress(buttonUp)==1|| getButtonPress(buttonRight)==1 ))// si la valeur de step est 3 et que soit le bouton Haut,Droit ou Bas est appuyé

																{
																step=0;//step prend la valeur 0
																displayCenteredBigTextLine(8,"code incorrect ");
																eraseDisplay();
																sleep(750);

																}
                                                            if (step==4 &&(getButtonPress(buttonLeft)==1||getButtonPress(buttonDown)==1|| getButtonPress(buttonRight)==1))// si la valeur de step est 4 et que soit le bouton Gauche,Droit ou Bas est appuyé

																{

																step=0;//step prend la valeur 0
																displayCenteredBigTextLine(8," code incorrect");
																eraseDisplay();
																sleep(750);

																}
				          }

										while (step==5  )//tant que la variable step a pour valeur 5
										{

															SensorType[S1] = sensorEV3_Ultrasonic;//Initialisation : un capteur ultrason est connecté sur l'entrée 1
															SensorType[S2] = sensorEV3_Ultrasonic;//Initialisation : un capteur ultrason est connecté sur l'entrée 2
															eraseDisplay();
															sleep(1000);
															displayCenteredBigTextLine(5," code bon");//affiche en grand et au centre le message "code bon"

															if (getUSDistance(S1)<15)//si l'obstacle est à moins de 15cm du capteur branché à l'entrée 1
																{
															setMotorTarget(motorA, 90, 10);
															sleep(2000);
															}
															if (SoN==0)//si la valeur de la variable SoN est 0
																{
																	son4();//faire jouer la fonction son4
																	SoN=1;//la varaible SoN a pour valeur 0
															  }
															if (getUSDistance(S2)>15 && getUSDistance(S1)>15 )//si l'obstacle est à plus de 15cm des capteurs branchés aux entrées 1 et 2
															{
															setMotorTarget(motorA, 0, 10);
															sleep(1000);

															}

														 	{
														 	step=0;//la variable step prend la valeur 0 sortie du mode protégé
														 	}


										}


								if ( getButtonPress(buttonRight)==true && getButtonPress(buttonDown)==true)//si le bouton droit est appuyé
										{
											mode=1;//la valeur de mode est 1 (on sort du mode protégé)
										}
            }
}
}
