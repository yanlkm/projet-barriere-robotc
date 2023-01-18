
task main()
{int mode=5;
	while (getButtonPress(buttonLeft)!=true || getButtonPress(buttonRight)!=true){
			 displayCenteredTextLine(10,"Bienvenue Barriere Automatix");
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
}
