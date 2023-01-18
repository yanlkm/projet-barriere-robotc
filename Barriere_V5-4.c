task main()
{	int mode=0;
	int step=0;



	while (getButtonPress(buttonLeft)!=true || getButtonPress(buttonRight)!=true)
{
				displayCenteredBigTextLine(2,"Bienvenue ");
				displayCenteredBigTextLine(5,"sur ");
				displayCenteredBigTextLine(7,"Barriere ");
				displayCenteredBigTextLine(10,"Automatix ");

}

			eraseDisplay();
			sleep(1000);


	while (!(getButtonPress(buttonUp)==1 && getButtonPress(buttonDown)==1) )
{

	displayCenteredBigTextLine(5," Fonctionnement");

	    if( getButtonPress(buttonRight)==true)
	    	  {
						mode=1;
					}
			if (getButtonPress(buttonLeft)==true)
				  {
						mode=2;
					}


				while (mode==1)
				{
						//mode libre
									SensorType[S1] = sensorEV3_Ultrasonic;
									SensorType[S2] = sensorEV3_Ultrasonic;

									displayCenteredBigTextLine(5," Mode Libre");

									if (getUSDistance(S1)<15)
										{
									setMotorTarget(motorA, 90, 10);
									sleep(2000);
									}
									if (getUSDistance(S2)>15 && getUSDistance(S1)>15 )
										{
									setMotorTarget(motorA, 0, 10);
									sleep(1000);}

								if (getButtonPress(buttonLeft)==true)
										{
											mode=2;
										}
				}

				while (mode==2)
		   	{
						//mode protégé
									SensorType[S1] = sensorEV3_Ultrasonic;
									SensorType[S2] = sensorEV3_Ultrasonic;
									displayCenteredBigTextLine(5," Mode Protege");
						while (step<5)

							{

												if (step==0 && getButtonPress(buttonRight)==1)
												{
														step=1;
														eraseDisplay();
														displayCenteredBigTextLine(8," code %d ",step);
														sleep(1000);
												}
												if (step==4 && getButtonPress(buttonUp)==1)
												{
														step=5;
														eraseDisplay();
														displayCenteredBigTextLine(8," code %d ",step);
														sleep(1000);
												}
												if (step==1 && getButtonPress(buttonRight)==1)
												{
													    step=2;
															eraseDisplay();
															displayCenteredBigTextLine(8," code %d ",step);
															sleep(1000);


												}
												if (step==2 && getButtonPress(buttonLeft)==1)
												{
												step=3;
												eraseDisplay();
												displayCenteredBigTextLine(8," code %d ",step);
												sleep(1000);
												}
												if (step==3 && getButtonPress(buttonLeft)==1)
												{
												step=4;
												eraseDisplay();
												displayCenteredBigTextLine(8," code %d ",step);
												sleep(1000);
												}


															if  (step==0 && (getButtonPress(buttonLeft)==1||getButtonPress(buttonUp)==1|| getButtonPress(buttonDown)==1 ))
																	{
																	step=0;
																	displayCenteredBigTextLine(8," Saisir le bon code ");
																	displayCenteredBigTextLine(11,"  bon code ");
																	sleep(500);
																	}
															if (step==1 && (getButtonPress(buttonLeft)==1||getButtonPress(buttonUp)==1|| getButtonPress(buttonDown)==1))

																{
																step=0;
																displayCenteredBigTextLine(8," Saisir le bon code ");
																displayCenteredBigTextLine(11,"  bon code ");
																sleep(500);
																}
															if (step==2 &&(getButtonPress(buttonDown)==1||getButtonPress(buttonUp)==1||getButtonPress(buttonRight)==1))

																{
																step=0;
																displayCenteredBigTextLine(8," Saisir le bon code ");
																displayCenteredBigTextLine(11,"  bon code ");
																sleep(500);
																}
															if (step==3 &&(getButtonPress(buttonDown)==1||getButtonPress(buttonUp)==1|| getButtonPress(buttonRight)==1 ))

																{
																step=0;
																displayCenteredBigTextLine(8," Saisir le bon code ");
																displayCenteredBigTextLine(11,"  bon code ");
																sleep(500);

																}
														if (step==4 &&(getButtonPress(buttonLeft)==1||getButtonPress(buttonDown)==1|| getButtonPress(buttonRight)==1))

																{

																step=0;
																displayCenteredBigTextLine(8," Saisir le bon code ");
																displayCenteredBigTextLine(11,"  bon code ");
																sleep(500);

																}
				          }

										while (step==5 || getButtonPress(buttonEnter)==0 )
										{

															SensorType[S1] = sensorEV3_Ultrasonic;
															SensorType[S2] = sensorEV3_Ultrasonic;
															eraseDisplay();
															sleep(1000);
															displayCenteredBigTextLine(5," code bon");

															if (getUSDistance(S1)<15)
																{
															setMotorTarget(motorA, 90, 10);
															sleep(2000);
															}
															if (getUSDistance(S2)>15 && getUSDistance(S1)>15 )
															{
															setMotorTarget(motorA, 0, 10);
															sleep(1000);

															}
															if ( getButtonPress(buttonLeft)==1)
														 	{
														 	step=0;
														 	}


										}


								if ( getButtonPress(buttonRight)==true)
										{
											mode=1;
										}
							}
}
}
