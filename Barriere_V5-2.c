
task main()
{int step=0;
	 while (1)
{

          	displayCenteredBigTextLine(5," Mode Protege");

							if (step==0 && getButtonPress(buttonRight)==1)
							{
									step=1;
									eraseDisplay();
									displayCenteredBigTextLine(8," code %d ",step);
									sleep(500);
						  }

							if (step==1 && getButtonPress(buttonLeft)==1)
							{
								    step=2;
										eraseDisplay();
										displayCenteredBigTextLine(8," code %d ",step);
										sleep(500);


							}
							if (step==2 && getButtonPress(buttonLeft)==1)
							{
							step=3;
							eraseDisplay();
							displayCenteredBigTextLine(8," code %d ",step);
							sleep(500);
							}
							if (step==3 && getButtonPress(buttonUp)==1)
							{
							step=4;
							eraseDisplay();
							displayCenteredBigTextLine(8," code %d ",step);
							sleep(500);
							}
							if (step==4&& getButtonPress(buttonRight)==1) { step=5; eraseDisplay(); displayCenteredTextLine(8," code %d ",step); sleep(500);}}}
