
void jouerMusique(){
setSoundVolume(1);

playTone(695, 14); while(bSoundActive){}
playTone(695, 14); while(bSoundActive){}
}

void jouerMusique1(){
setSoundVolume(1);
playTone(1251, 14); while(bSoundActive){}
playTone(1188, 14); while(bSoundActive){}
playTone(1054, 14); while(bSoundActive){}


}
task main()
{int mode=5;
	while (getButtonPress(buttonLeft)!=true || getButtonPress(buttonRight)!=true){
			 displayCenteredBigTextLine(10,"Bienvenue ");
	}

	eraseDisplay();
	sleep(1000);
	while (getButtonPress(buttonUp)!=true || getButtonPress(buttonDown)!=true ){

	    	displayCenteredBigTextLine(5," Fonctionnement");

	    		if ( getButtonPress(buttonRight)==true) {
						mode=1;
					}
					if (getButtonPress(buttonLeft)==true) {
						mode=2;
					}


				while (mode==1) {
				//mode libre

				displayCenteredBigTextLine(5," Mode Libre");

									SensorType[S1] = sensorEV3_Ultrasonic;
									SensorType[S2] = sensorEV3_Ultrasonic;
									//setSensorMode(S1,modeEV3Ultrasonic_Cm);

									if (getUSDistance(S1)<15)
										{
									setMotorTarget(motorA, 90, 10);
									sleep(2000);
									}
									if (getUSDistance(S2)>15 && getUSDistance(S1)>15 )
										{
									setMotorTarget(motorA, 0, 10);
									sleep(1000);}
									}

						if (getButtonPress(buttonLeft)==true) {
						mode=2;
							}
				}

				while (mode==2) {
				//mode protégé

				displayCenteredBigTextLine(5," Mode Protege");
				if ( getButtonPress(buttonRight)==true) {
						mode=1;
					}
				}
}
