#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

// Initializing Dimensions.
// resolutionX and resolutionY determine the rendering resolution.

const int resolutionX = 960;
const int resolutionY = 640;
const int boxPixelsX = 32;
const int boxPixelsY = 32;
const int gameRows = resolutionX / boxPixelsX; // Total rows on grid
const int gameColumns = resolutionY / boxPixelsY; // Total columns on grid

// Initializing GameGrid.

int gameGrid[gameRows][gameColumns] = {};




void drawPlayer(RenderWindow& window, float& player_x, float& player_y, Sprite& playerSprite);
void moveBullet(float& bullet_y, bool& bullet_exists, Clock& bulletClock);
void drawBullet(RenderWindow& window, float& bullet_x, float& bullet_y, Sprite& bulletSprite);

/////////////////////////////////////////////////////////////////////////////
//                                                                         //
// Write your functions declarations here. Some have been written for you. //
//                                                                         //
//////////////////////////////////////////////////////////ch///////////////////

void movement(float& player_x);

void firing(bool& bullet_exists, float& player_x, float& bullet_x, float& bullet_y, float& player_y, int bulletsLeft[], int& activeCan, int totalCans);

void drawSprayCans(RenderWindow& window, Sprite playerSprite, int bulletsLeft[], int& activeCan, int totalCans, float sprayCanPositionsX[], float sprayCanPositionY );

void shootBullet(bool& bullet_exists, int bulletsLeft[], int& activeCan, int totalCans );


bool menutable(RenderWindow& window);

bool resumetable(RenderWindow& window);

bool levels(RenderWindow& window, int& gamelevel);

void initializeBees(Sprite beeSprites[], Texture& beeTexture, const int& beecount, float beeX[], float beeY[], float beeSpeedX[],bool beeAlive[]);

void initializeRedBees(Sprite killerbeeSprites[], Texture& killerbeeTexture, const int& redbeecount, float redbeeX[], float redbeeY[], float redbeeSpeedX[],bool redBeeAlive[]);


void moveBees(Sprite beeSprites[], const int& beecount, float beeX[], float beeY[], float beeSpeedX[], bool beeAlive[],float honeycombX[],float honeycombY[], bool combactive[],const int& redbeecount,bool redbeecomb[],float redhoneycombX[],float redhoneycombY[]);

void moveRedBees(Sprite killerbeeSprites[], const int& redbeecount, float redbeeX[], float redbeeY[], float redbeeSpeedX[], bool redBeeAlive[],float honeycombX[],float honeycombY[], bool combactive[], const int& beecount,bool redbeecomb[],float redhoneycombX[],float redhoneycombY[]);


void randombees(float beeX[], float beeY[], const int& beecount, int& currentBeeCount, Clock& beeTimer,bool beeAlive[]);

void randomredbees(float redbeeX[], float redbeeY[], const int& redbeecount, int& currentRedBeeCount, Clock& redbeeTimer,bool redBeeAlive[]);


void checkCollision(bool& bullet_exists, float& bullet_x, float& bullet_y, float beeX[], float beeY[], int& currentBeeCount, float beeWidth, float beeHeight, bool beeAlive[],bool combactive[],float honeycombX[],float honeycombY[], int& score);

void checkcombCollision(bool& bullet_exists, float& bullet_x, float& bullet_y, float honeycombX[], float honeycombY[], int& currentBeeCount, float beeWidth, float beeHeight, bool combactive[]);

void redBeeCollision(bool& bullet_exists, float& bullet_x, float& bullet_y, float redbeeX[], float redbeeY[], int& currentRedBeeCount, float beeWidth, float beeHeight, bool redBeeAlive[],bool redbeecomb[],float redhoneycombX[], float redhoneycombY[], int& score, int gamelevel);

void redCombCollision(bool& bullet_exists, float& bullet_x, float& bullet_y, float redhoneycombX[], float redhoneycombY[], int& currentRedBeeCount, float beeWidth, float beeHeight,bool redbeecomb[]);


void flowering(float beeY[], int& currentBeeCount, int& currentFlowerCount, const int& maxFlowers, float flowerX[], float flowerY[], Sprite flowerSprites[], bool flowerCollisionCheck[], float groundY, int& currentRedBeeCount, float redbeeY[]);

void moveFlowers(int& currentFlowerCount, float flowerY[], float flowerX[], Sprite flowerSprites[]);

void checkCanCollision(float& player_x, float& player_y, const float& boxPixelsX, const float& boxPixelsY, int& currentFlowerCount, float flowerX[], float flowerY[], int resolutionX);

void drawFlowers(RenderWindow& window, int& currentFlowerCount, Sprite flowerSprites[], bool flowerCollisionCheck[]);

void displayScore(RenderWindow& window, Font& font, int& score);

void moveHummingbird(bool& hummingbirdActive, float& hb_x, float& hb_y, float hb_speed, float honeycombX[], float honeycombY[], bool combactive[], int beecount, Sprite& birdSprite, Clock& stayClock, float stayTime, float redhoneycombX[], float redhoneycombY[], bool redbeecomb[], int redbeecount, int& score);                     

void checkHummingbirdCollision(float honeycombX[], float honeycombY[], bool combactive[], int& score, int beecount, float hb_x, float hb_y, float redhoneycombX[], float redhoneycombY[], bool redbeecomb[], int redbeecount);

void checkHummingbirdSick(bool& bullet_exists, float bullet_x, float bullet_y, float hb_x, float hb_y, bool& hummingbirdActive, Clock& hbClock);

void renderHummingbird(RenderWindow& window,bool& hummingbirdActive,Sprite& birdSprite);

void generateBeehive(float beeX[], float beeY[], bool beeAlive[], bool& isBeeStuck, int beecount, Clock& stuckClock, float stuckTime, float& beehiveX, float& beehiveY, bool& beehiveActive);

void renderBeehive(RenderWindow& window, bool& beehiveActive, Sprite& hiveSprite, float beehiveX, float beehiveY);

void checkBeehiveCollision(float bullet_x, float bullet_y, bool& bullet_exists,const float boxPixelsX, const float boxPixelsY, bool hiveActive[], float hiveX[], float hiveY[], const int preGenBeeHive);

void preGenHoneyCombs(float honeycombX[], float honeycombY[], const int preGenComb,bool combactive[]);

void renderPreGenComb(RenderWindow& window, Sprite& honeycombSprite, float honeycombX[], float honeycombY[], bool combactive[], const int preGenComb);

void transitionLevel(RenderWindow& window, int gamelevel);

void gameOver(RenderWindow& window);

bool isSprayCanBlocked(float player_x, float flowerX[], float flowerY[], int currentFlowerCount);
      
bool checkLevelComplete(int& score, bool beeAlive[], bool combactive[], int beecount, int redbeecount, bool redbeecomb[], bool redBeeAlive[]);

void renderPreGenBeeHives(RenderWindow& window, Sprite hiveSprites[], float hiveX[], float hiveY[], bool hiveActive[], const int preGenBeeHive);

void preGenBeeHives(float hiveX[], float hiveY[], const int preGenBeeHive, bool hiveActive[]);

///////////////////////////////////////////////////



void resetLevel(int& gamelevel, int& currentBeeCount, int& currentRedBeeCount, 
                int& currentFlowerCount, int& beetmp, int& redtmp, 
                int& flowertmp, int& pregentmp, 
                bool beeAlive[], bool combactive[], float honeycombX[], 
                float honeycombY[], bool redBeeAlive[], bool redbeecomb[], 
                float redhoneycombX[], float redhoneycombY[], 
                float flowerX[], float flowerY[], int& score, const int beecount, const int redbeecount) {
    
    // Check if maximum level is reached
    //if (gamelevel < 1 || gamelevel > 4) {
   // cout << "Unexpected level: " << gamelevel << endl;
  //  return;
//}

    
    // Reset counts and score
    currentBeeCount = 0;
    currentRedBeeCount = 0;
    currentFlowerCount = 0;
    score = 0;

    // Reset level-specific configurations
    switch(gamelevel) {
        case 1:
            beetmp = 20;
            redtmp = 0;
            flowertmp = 20;
            pregentmp = 3;
            break;
        case 2:
            beetmp = 15;
            redtmp = 5;
            flowertmp = 20;
            pregentmp = 9;
            break;
        case 3:
            beetmp = 20;
            redtmp = 10;
            flowertmp = 30;
            pregentmp = 15;
            break;
        case 4:
            beetmp = 20;
            redtmp = 15;
            flowertmp = 35;
            pregentmp = 15;
            break;
        default:
            // Handle unexpected level
            cout << "Unexpected level: " << gamelevel << endl;
            return;
    }


    // Reset bees and honeycombs
    for (int i = 0; i < beetmp; ++i) {
        beeAlive[i] = false;
        combactive[i] = false;
        honeycombX[i] = -100; // Move off-screen
        honeycombY[i] = -100; // Move off-screen
    }

    // Reset red bees and red honeycombs
    for (int i = 0; i < redtmp; ++i) {
        redBeeAlive[i] = false;
        redbeecomb[i] = false;
        redhoneycombX[i] = -100; // Move off-screen
        redhoneycombY[i] = -100; // Move off-screen
    }

    // Reset flowers
    for (int i = 0; i < flowertmp; ++i) {
        flowerX[i] = -100; // Move off-screen
        flowerY[i] = -100; // Move off-screen
    }
}


int main(){

	srand(time(0));

	// Declaring RenderWindow.
	RenderWindow window(VideoMode(resolutionX, resolutionY), "Buzz Bombers", Style::Close | Style::Titlebar);

	// Used to position your window on every launch. Use according to your needs.
	
	window.setPosition(Vector2i(500, 200));

	// Initializing Background Music.
	Music bgMusic;
	if (!bgMusic.openFromFile("Music/theme.ogg")) {
	cout << "Error: Could not load music file!" << endl;
	}
	bgMusic.setVolume(50);
	bgMusic.setLoop(true);
	bgMusic.play();
	
	Music bulletfire;

	// Load the audio file once
	if (!bulletfire.openFromFile("Music/kar98.ogg")) {
	    cout << "Error: Could not load music file!" << endl;
	}

	bulletfire.setVolume(100);
	bulletfire.setLoop(false);
	
	Music revolver;

	// Load the audio file once
	if (!revolver.openFromFile("Music/revolver.ogg")) {
	    cout << "Error: Could not load music file!" << endl;
	}

	revolver.setVolume(100);
	revolver.setLoop(false);


	// Initializing Player and Player Sprites.
	float player_x = (gameRows / 2) * boxPixelsX;
	float player_y = (gameColumns - 4) * boxPixelsY;

	Texture playerTexture;
	Sprite playerSprite;
	playerTexture.loadFromFile("Textures/spray.png");
	playerSprite.setTexture(playerTexture);

	//Handling sprays cans as lives
		
	const int totalCans = 3;       
	int bulletsPerCan = 56;        
	int activeCan = 0;             
	int bulletsLeft[totalCans] = {56, 56, 56}; 

	float sprayCanPositionsX[totalCans] = {20, 80, 140}; 
	float sprayCanPositionY = (gameColumns - 2) * boxPixelsY ;
		
	Texture sprayCanTexture;
	Sprite sprayCanSprite;

	
	if (!sprayCanTexture.loadFromFile("Textures/spray.png")) {
	    cout << "Error: Could not load spray can texture!" << endl;
	
	}
	sprayCanSprite.setTexture(sprayCanTexture);


	// The ground on which player moves


	RectangleShape groundRectangle(Vector2f(960, 64));
	groundRectangle.setPosition(0, (gameColumns - 2) * boxPixelsY);
	groundRectangle.setFillColor(Color::Green);




	float bullet_x = player_x;
	float bullet_y = player_y;
	bool bullet_exists = true;

	Clock bulletClock;

	Texture bulletTexture;
	Sprite bulletSprite;
	bulletTexture.loadFromFile("Textures/bullet.png");
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setScale(3, 3);
	bulletSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));


	//Honey comb texture

	Texture honeycombTexture;
	Sprite honeycombSprite;
	honeycombTexture.loadFromFile("Textures/honeycomb.png");
	honeycombSprite.setTexture(honeycombTexture);
	

	//Bird Texture

	Texture birdTexture;
	Sprite birdSprite;
	birdTexture.loadFromFile("Textures/bird2.png");
	birdSprite.setTexture(birdTexture);
	birdSprite.setScale(1.5, 1.5);

	birdSprite.setPosition(resolutionX / 2, resolutionY / 2); // Initial position at the center

	// Variables for movement
	
	float hb_x = resolutionX / 2, hb_y = resolutionY / 2;
	float hb_speed = 5.0f;  // Speed of hummingbird
	
	bool hummingbirdActive = true;  
	
	Clock hbClock; 
	
	Clock stayClock;
	float stayTime = 10.0f;
	
	
	//Hive Texture and working for pre generated hives in level 4

	const int preGenBeeHive = 5; // Number of pre-generated hives
	float hiveX[preGenBeeHive];
	float hiveY[preGenBeeHive];
	bool hiveActive[preGenBeeHive] = { false };

	Texture hiveTexture;
	if (!hiveTexture.loadFromFile("Textures/hive.png")) {
	    cout << "Error: Could not load beehive texture!" << endl;
	    return -1;
	}

	Sprite hiveSprites[preGenBeeHive];
	for (int i = 0; i < preGenBeeHive; i++) {
	    hiveSprites[i].setTexture(hiveTexture);
	}


	// Killer bee comb(Red Comb)

	Texture redcombTexture;
	Sprite redcombSprite;
	redcombTexture.loadFromFile("Textures/honeycomb_red.png");
	redcombSprite.setTexture(redcombTexture);

	//Working for worker bees
	
	int gamelevel=1;
	
	//Menu Table

	if (!menutable(window)) { //Calling menu function here because it will appear in start and if I place it in loop then it appears for every iritation
		return 0;
	}
	
	//Levels table
	
	if (!levels(window,gamelevel)) { 
		return 0;
	}
	
	int beetmp = 0;
	int redtmp = 0;
	int flowertmp = 0;
	int pregentmp = 0;
	
	if(gamelevel == 1){
		beetmp = 20;
		redtmp = 0;
		flowertmp=20;
		pregentmp=3;
	}
	else if(gamelevel == 2){
		beetmp = 15;
		redtmp = 5;
		flowertmp=20;
		pregentmp=9;
	}
	else if(gamelevel == 3){
		beetmp = 20;
		redtmp = 10; 
		flowertmp=30;
		pregentmp=15;
	}
	else if(gamelevel == 4){
		beetmp = 20;
		redtmp = 15;
		flowertmp = 35;
		pregentmp = 15;
		
	preGenBeeHives(hiveX, hiveY, preGenBeeHive, hiveActive);	
	}
	
	const int preGenComb = pregentmp;
	
	const int beecount = beetmp;
	int currentBeeCount = 0;
	float beeX[beecount];
	float beeY[beecount];
	float beeSpeedX[beecount];
	Clock beeTimer;
	float honeycombX[beecount]; 
	float honeycombY[beecount]; 
	Sprite honeycombSprites[beecount]; 
	
	Texture beeTexture;
	if (!beeTexture.loadFromFile("Textures/Regular_bee.png")) {
		cout << "Error: Could not load bee texture!" << endl;
		return -1;
	}
	Sprite beeSprites[beecount];

	bool beeAlive[beecount] = { false }; 
	bool combactive[beecount] = { false };
	for (int i = 0; i < beecount; i++) {
		beeAlive[i] = false;	
		combactive[i] = false;
	}
	
	
	
	
	for (int i = 0; i < beecount; ++i) {
		honeycombSprites[i].setTexture(honeycombTexture);
		honeycombX[i] = -100; 
		honeycombY[i] = -100; 
		honeycombSprites[i].setPosition(honeycombX[i], honeycombY[i]);
		
		
	}
	
	
	//Killer Bee and its working
	
	const int redbeecount = redtmp;
	int currentRedBeeCount = 0;
	float redbeeX[redbeecount];
	float redbeeY[redbeecount];
	float redbeeSpeedX[redbeecount];
	Clock redBeeTimer;
	float redhoneycombX[redbeecount]; 
	float redhoneycombY[redbeecount];
	Sprite redhoneycombSprites[redbeecount];
	
	Texture killerbeeTexture;
	if (!killerbeeTexture.loadFromFile("Textures/Fast_bee.png")) {
		cout << "Error: Could not load bee texture!" << endl;
		return -1;
	}
	
	Sprite killerbeeSprites[redbeecount];
	
	bool redBeeAlive[redbeecount] = { false }; 
	bool redbeecomb[redbeecount] = { false };
	
	for (int i = 0; i < redbeecount; i++) {
		beeAlive[i] = false;
		redbeecomb[i] = false;
	}
	
	for (int i = 0; i < redbeecount; ++i) {
		redhoneycombSprites[i].setTexture(redcombTexture);
		redhoneycombX[i] = -100; 
		redhoneycombY[i] = -100; 
		redhoneycombSprites[i].setPosition(redhoneycombX[i], redhoneycombY[i]);
		
		
	}

	preGenHoneyCombs( honeycombX, honeycombY, preGenComb, combactive);


	initializeBees(beeSprites, beeTexture, beecount, beeX, beeY, beeSpeedX,beeAlive);
	initializeRedBees(killerbeeSprites, killerbeeTexture, redbeecount, redbeeX, redbeeY, redbeeSpeedX,redBeeAlive);

	const int maxFlowers = flowertmp;
	int currentFlowerCount = 0;

	float flowerX[maxFlowers];
	float flowerY[maxFlowers];

	bool flowerCollisionCheck[beecount] = { false };
	
	for(int i=0; i<maxFlowers;i++){
		flowerCollisionCheck[i]=false;
	}

	// Create an array of flower sprites
	Sprite flowerSprites[maxFlowers];

	Texture flowerTexture;
	if (!flowerTexture.loadFromFile("Textures/obstacles.png")) {
		cout << "Error: Could not load flower texture!" << endl;
		return -1;
	}

	for (int i = 0; i < maxFlowers; ++i) {
		flowerSprites[i].setTexture(flowerTexture);
		flowerSprites[i].setPosition(-100, -100);
	} 
	

	// Score Declaration

	int score = 00000;
	float groundY = (gameColumns - 2) * boxPixelsY;
	
	
	
	
	//initializePowerUpTextures();
	

	while (window.isOpen()) {

		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				return 0;
			}
		}

		///////////////////////////////////////////////////////////////
		//                                                           //
		// Call Your Functions Here. Some have been written for you. //
		// Be vary of the order you call them, SFML draws in order.  //
		//                                                           //
		///////////////////////////////////////////////////////////////


		Font font;
		if (!font.loadFromFile("Fonts/arial.ttf")) {
			cout << "Error: Could not load font file!" << endl;
			return -1;
		}
		
		//Unique background for each level

		if(gamelevel == 1){
			Texture level1Texture;
		    if (!level1Texture.loadFromFile("Textures/level1.jpg")) {
			cout << "Error: Could not load levels background image!" << endl;
			
	    	}

	   	 // Create a sprite for the background
	    	Sprite level1Sprite(level1Texture);
	    	level1Sprite.setPosition(0, 0);
	    	
	    	window.draw(level1Sprite);
	    	
	    	
		}
		
		else if(gamelevel==2){
			Texture level2Texture;
		    if (!level2Texture.loadFromFile("Textures/level2.jpg")) {
			cout << "Error: Could not load levels background image!" << endl;
			
	    	}

	   	 // Create a sprite for the background
	    	Sprite level2Sprite(level2Texture);
	    	level2Sprite.setPosition(0, 0);
	    	
	    	window.draw(level2Sprite);

	    	
		}
		
		else if(gamelevel==3){
			Texture level3Texture;
		    if (!level3Texture.loadFromFile("Textures/level3.jpg")) {
			cout << "Error: Could not load levels background image!" << endl;
			
	    	}

	   	 // Create a sprite for the background
	    	Sprite level3Sprite(level3Texture);
	    	level3Sprite.setPosition(0, 0);
	    	
	    	window.draw(level3Sprite);
		}
		
		else if(gamelevel==4){
			Texture level4Texture;
		    if (!level4Texture.loadFromFile("Textures/level4.jpg")) {
			cout << "Error: Could not load levels background image!" << endl;
			
	    	}

	   	 // Create a sprite for the background
	    	Sprite level4Sprite(level4Texture);
	    	level4Sprite.setPosition(0, 0);
	    	
	    	window.draw(level4Sprite);
		}


		 if (gamelevel >= 1 && gamelevel < 4) {

		    if (checkLevelComplete(score,beeAlive,combactive,beecount,redbeecount,redbeecomb,redBeeAlive)){

		    transitionLevel( window, gamelevel);
		    levels(window,gamelevel);

		    resetLevel(gamelevel, currentBeeCount,
		currentRedBeeCount,currentFlowerCount, beetmp, redtmp,flowertmp,
		pregentmp, beeAlive, combactive,honeycombX, honeycombY, redBeeAlive,
		redbeecomb,redhoneycombX, redhoneycombY, flowerX, flowerY, score,
		beecount, redbeecount);

		    preGenHoneyCombs( honeycombX, honeycombY, preGenComb, combactive);
		    initializeBees(beeSprites, beeTexture, beecount, beeX, beeY,
		beeSpeedX,beeAlive);
		initializeRedBees(killerbeeSprites, killerbeeTexture, redbeecount,
		redbeeX, redbeeY, redbeeSpeedX,redBeeAlive);


		    }

		    } else if (gamelevel == 4 &&
		checkLevelComplete(score,beeAlive,combactive,beecount,redbeecount,redbeecomb,redBeeAlive))
		{
		    // game over
		    gameOver(window);
		    return 0;

		    }



		randombees( beeX, beeY, beecount, currentBeeCount,beeTimer,beeAlive);
		randomredbees( redbeeX, redbeeY, redbeecount, currentRedBeeCount,redBeeTimer,redBeeAlive);
		
		
		//Normal Bees
		checkCollision(bullet_exists,bullet_x, bullet_y, beeX, beeY,currentBeeCount, 32, 32, beeAlive,combactive,honeycombX, honeycombY, score);
		//Normal bees comb collision with bullets and disappears
		checkcombCollision(bullet_exists, bullet_x, bullet_y, honeycombX, honeycombY, currentBeeCount, 32, 32, combactive);
		//Killer Bees
		
		redBeeCollision(bullet_exists,bullet_x, bullet_y, redbeeX, redbeeY,currentRedBeeCount, 32, 32, redBeeAlive,redbeecomb,redhoneycombX, redhoneycombY, score, gamelevel);
		
		//Red comb collision with bullets and disappers
		
		redCombCollision(bullet_exists, bullet_x, bullet_y, redhoneycombX, redhoneycombY, currentRedBeeCount, 32, 32, redbeecomb);
		
		
		//Beehive collision with bullets
		checkBeehiveCollision(bullet_x, bullet_y, bullet_exists, boxPixelsX, boxPixelsY, hiveActive, hiveX, hiveY, preGenBeeHive);

		
		//Normal Bees
		for (int i = 0; i < currentBeeCount; i++) {
			if (beeAlive[i]) {
				beeSprites[i].setPosition(beeX[i], beeY[i]);
				window.draw(beeSprites[i]);
				
			}
			
		}
		for (int i = 0; i < currentBeeCount; i++) {
    			if (combactive[i]) {
        			honeycombSprites[i].setPosition(honeycombX[i], honeycombY[i]);
        			window.draw(honeycombSprites[i]);
    			}
		}

		//Killer Bees
		for (int i = 0; i < currentRedBeeCount; i++) {
			if (redBeeAlive[i]) {
				killerbeeSprites[i].setPosition(redbeeX[i], redbeeY[i]);
				window.draw(killerbeeSprites[i]);
			}
			
		}
		for (int i = 0; i < currentRedBeeCount; i++) {
    			if (redbeecomb[i]) {
        			redhoneycombSprites[i].setPosition(redhoneycombX[i], redhoneycombY[i]);
        			window.draw(redhoneycombSprites[i]);
   			 }
   		} 
    
	//For Normal Bees
	moveBees(beeSprites, beecount, beeX, beeY, beeSpeedX, beeAlive, honeycombX, honeycombY, combactive, redbeecount, redbeecomb, redhoneycombX, redhoneycombY);
	//For Killer bees
	moveRedBees(killerbeeSprites, redbeecount, redbeeX, redbeeY, redbeeSpeedX, redBeeAlive,honeycombX, honeycombY, combactive, beecount, redbeecomb, redhoneycombX, redhoneycombY);	



	moveHummingbird(hummingbirdActive, hb_x, hb_y, hb_speed, honeycombX, honeycombY, combactive, beecount, birdSprite, stayClock, stayTime, redhoneycombX, redhoneycombY, redbeecomb, redbeecount, score);

	checkHummingbirdCollision( honeycombX, honeycombY, combactive, score, beecount, hb_x, hb_y, redhoneycombX, redhoneycombY, redbeecomb, redbeecount);

	checkHummingbirdSick( bullet_exists, bullet_x, bullet_y, hb_x, hb_y, hummingbirdActive, hbClock);



	flowering(beeY, currentBeeCount, currentFlowerCount, maxFlowers, flowerX, flowerY, flowerSprites, flowerCollisionCheck, groundY, currentRedBeeCount, redbeeY);

	
	checkCanCollision(player_x, player_y, boxPixelsX, boxPixelsY, currentFlowerCount, flowerX, flowerY, resolutionX);


    if (Keyboard::isKeyPressed(Keyboard::Space)) {
	
		if(bullet_exists == true){
		
			 bulletfire.play();
		}
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Num1)) {
	
		revolver.play();
	}
	if (Keyboard::isKeyPressed(Keyboard::Num2)) {
	
		revolver.play();
	}
	if (Keyboard::isKeyPressed(Keyboard::Num3)) {
	
			 revolver.play();
	}
	

		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			resumetable(window);
		}
		
		movement (player_x);

		if (!bullet_exists) {
			bullet_x = player_x;
		}

		firing(bullet_exists, player_x, bullet_x, bullet_y, player_y, bulletsLeft, activeCan, totalCans);

		if (bullet_exists == true)
		{
			moveBullet(bullet_y, bullet_exists, bulletClock);
			drawBullet(window, bullet_x, bullet_y, bulletSprite);
		}
		else
		{
			bullet_x = player_x;
			bullet_y = player_y;
		}
		
		

		drawPlayer(window, player_x, player_y, playerSprite);
		
		drawFlowers(window, currentFlowerCount, flowerSprites, flowerCollisionCheck);
		
		renderPreGenComb(window, honeycombSprite, honeycombX, honeycombY, combactive, preGenComb);
		
		renderPreGenBeeHives(window, hiveSprites, hiveX, hiveY, hiveActive, preGenBeeHive);
		
		window.draw(groundRectangle);

		drawSprayCans(window, playerSprite, bulletsLeft, activeCan, totalCans, sprayCanPositionsX, sprayCanPositionY);

		
		renderHummingbird(window,hummingbirdActive,birdSprite);
		
		displayScore(window, font, score);
		
		window.display();
		
		window.clear();
	}


}

////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Write your functions definitions here. Some have been written for you. //
//                                                                        //
////////////////////////////////////////////////////////////////////////////


void drawPlayer(RenderWindow& window, float& player_x, float& player_y, Sprite& playerSprite) {
	playerSprite.setPosition(player_x, player_y);
	window.draw(playerSprite);
}
void moveBullet(float& bullet_y, bool& bullet_exists, Clock& bulletClock) {
	if (bulletClock.getElapsedTime().asMilliseconds() < 20)
		return;

	bulletClock.restart();
	bullet_y -= 10;
	if (bullet_y < -32)
		bullet_exists = false;
}
void drawBullet(RenderWindow& window, float& bullet_x, float& bullet_y, Sprite& bulletSprite) {
	bulletSprite.setPosition(bullet_x, bullet_y);
	window.draw(bulletSprite);
}

void movement(float& player_x) {

	if (Keyboard::isKeyPressed(Keyboard::Left) && player_x > 0) {
		player_x -= 10.0;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) && player_x < resolutionX - boxPixelsX) {
		player_x += 10.0;
	}
}

void firing(bool& bullet_exists, float& player_x, float& bullet_x, float& bullet_y, float& player_y, int bulletsLeft[], int& activeCan, int totalCans) {

	if (Keyboard::isKeyPressed(Keyboard::Space) && !bullet_exists) {
		bullet_exists = true;
		bullet_x = player_x;
		bullet_y = player_y;
		shootBullet(bullet_exists, bulletsLeft, activeCan, totalCans);

	}

}

void drawSprayCans(RenderWindow& window, Sprite playerSprite, int bulletsLeft[], int& activeCan, int totalCans, float sprayCanPositionsX[], float sprayCanPositionY) {

    for (int i = 0; i < totalCans; ++i) {

        if (i >= activeCan) { 
        
            playerSprite.setPosition(sprayCanPositionsX[i], sprayCanPositionY);
            playerSprite.setScale(0.5, 0.5); 
            window.draw(playerSprite);

            Font font;
            if (!font.loadFromFile("Fonts/arial.ttf")) {
                cout << "Error: Could not load font!" << endl;
                return;
            }

            Text bulletCount;
            bulletCount.setFont(font);
            bulletCount.setCharacterSize(14);  // Smaller text
            bulletCount.setFillColor(Color::Black);
            bulletCount.setString(to_string(bulletsLeft[i])); // Remaining bullets
            bulletCount.setPosition(sprayCanPositionsX[i], sprayCanPositionY + 40); // Position below the spray can
            window.draw(bulletCount);
        }
    }
}

void shootBullet(bool& bullet_exists, int bulletsLeft[], int& activeCan, int totalCans ) {

    if (bulletsLeft[activeCan] > 0) {
        bulletsLeft[activeCan]--; 

    }
    else if (activeCan < totalCans - 1) {
    
        activeCan++; 
    } 
    else {
    
    	bullet_exists = false;
        cout << "No more spray cans left!" << endl;
        
    }
}


bool menutable(RenderWindow& window) {

	Texture backgroundTexture;
	    if (!backgroundTexture.loadFromFile("Textures/background.jpg")) {
		cout << "Error: Could not load levels background image!" << endl;
		return false;
	    }

	    // Create a sprite for the background
	    Sprite backgroundSprite(backgroundTexture);
	    backgroundSprite.setPosition(0, 0);
	    


	Font font1;
	if (!font1.loadFromFile("Fonts/Good-Game.ttf")) {
		cout << "Error: Could not load music file!" << endl;
		return false;
	}

	Font font;
	if (!font.loadFromFile("Fonts/Brush-Gaming-Font.ttf")) {
		cout << "Error: Could not load music file!" << endl;
		return false;
	}

	Text menu("Buzz Bomber", font, 60);
	menu.setPosition(resolutionX / 2 - 100, 100);
	menu.setFillColor(Color::Green);

	Text start("1. Start Game",font1, 40);
	start.setPosition(resolutionX / 2 - 100, 200);
	start.setFillColor(Color::White);

	Text exit("2. Exit Game", font1, 40);
	exit.setPosition(resolutionX / 2 - 100, 300);
	exit.setFillColor(Color::White);

	while (true) {

		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
				return false;
			}

			if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::Num1) {
					return true;
				}
				if (e.key.code == Keyboard::Num2) {
					window.close();
					return false;
				}
			}
		}
		window.clear();
		window.draw(backgroundSprite);
		window.draw(menu);
		window.draw(start);
		window.draw(exit);
		window.display();
	}
	return false;
}

bool resumetable(RenderWindow& window) {

	Texture backgroundTexture;
	    if (!backgroundTexture.loadFromFile("Textures/background.jpg")) {
		cout << "Error: Could not load levels background image!" << endl;
		return false;
	    }


	    Sprite backgroundSprite(backgroundTexture);
	    backgroundSprite.setPosition(0, 0);
	    

	Font font1;
	if (!font1.loadFromFile("Fonts/Good-Game.ttf")) {
		cout << "Error: Could not load music file!" << endl;
		return false;
	}

	Font font;
	if (!font.loadFromFile("Fonts/Brush-Gaming-Font.ttf")) {
		cout << "Error: Could not load music file!" << endl;
		return false;
	}

	Text menu("Buzz Bomber", font, 60);
	menu.setPosition(resolutionX / 2 - 100, 100);
	menu.setFillColor(Color::Green);

	Text start("1. Resume Game", font1, 40);
	start.setPosition(resolutionX / 2 - 100, 200);
	start.setFillColor(Color::White);

	Text exit("2. Exit Game", font1, 40);
	exit.setPosition(resolutionX / 2 - 100, 300);
	exit.setFillColor(Color::White);

	while (true) {

		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
				return false;
			}
			
			
			if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::Num1) {
					return true;
				}
				if (e.key.code == Keyboard::Num2) {
					window.close();
					return false;
				}
			}
		}
		window.clear();
		window.draw(backgroundSprite);
		window.draw(menu);
		window.draw(start);
		window.draw(exit);
		window.display();
	}
	return false;
}

bool levels(RenderWindow& window, int& gamelevel) {

	Texture backgroundTexture;
	    if (!backgroundTexture.loadFromFile("Textures/background.jpg")) {
		cout << "Error: Could not load levels background image!" << endl;
		return false;
	    }

	    Sprite backgroundSprite(backgroundTexture);
	    backgroundSprite.setPosition(0, 0);


	Font font1;
	if (!font1.loadFromFile("Fonts/Good-Game.ttf")) {
		cout << "Error: Could not load music file!" << endl;
		return false;
	}

	Font font;
	if (!font.loadFromFile("Fonts/Brush-Gaming-Font.ttf")) {
		cout << "Error: Could not load music file!" << endl;
		return false;
	}

	Text level("LEVELS", font, 60);
	level.setPosition(resolutionX / 2 - 100, 100);
	level.setFillColor(Color::Green);

	Text l1("1. Level 1", font1, 40);
	l1.setPosition(resolutionX / 2 - 100, 200);
	l1.setFillColor(Color::White);

	Text l2("2. Level 2", font1, 40);
	l2.setPosition(resolutionX / 2 - 100, 300);
	l2.setFillColor(Color::White);

	Text l3("3. Level 3", font1, 40);
	l3.setPosition(resolutionX / 2 - 100, 400);
	l3.setFillColor(Color::White);

	Text l4("4. Boss Level", font1, 40);
	l4.setPosition(resolutionX / 2 - 100, 500);
	l4.setFillColor(Color::White);


	while (true) {

		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
				return false;
			}

			if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::Num1) {
					gamelevel=1;
					return true;
				}
				if (e.key.code == Keyboard::Num2) {
					gamelevel=2;
					return true;
				}
				if (e.key.code == Keyboard::Num3) {
					gamelevel=3;
					return true;
				}
				if (e.key.code == Keyboard::Num4) {
					gamelevel=4;
					return true;
				}
			}
		}
		window.clear();
		window.draw(backgroundSprite);
		window.draw(level);
		window.draw(l1);
		window.draw(l2);
		window.draw(l3);
		window.draw(l4);
		window.display();
	}
	return false;
}

//For Normal Bees

void initializeBees(Sprite beeSprites[], Texture& beeTexture, const int& beecount, float beeX[], float beeY[], float beeSpeedX[],bool beeAlive[]) {

	for (int i = 0; i < beecount; ++i) {
		beeSprites[i].setTexture(beeTexture);

		beeX[i] = rand() % resolutionX;
		beeY[i] = -100; 
		beeAlive[i] = true;
		beeSpeedX[i] = -5.0f;
	}
}

//For Killer Bees 

void initializeRedBees(Sprite killerbeeSprites[], Texture& killerbeeTexture, const int& redbeecount, float redbeeX[], float redbeeY[], float redbeeSpeedX[],bool redBeeAlive[]) {

	for (int i = 0; i < redbeecount; ++i) {
		killerbeeSprites[i].setTexture(killerbeeTexture);

		redbeeX[i] = rand() % resolutionX;
		redbeeY[i] = -100; 
		redBeeAlive[i] = true;
		redbeeSpeedX[i] = -10.5f;
	}
}

//For Normal bees

void moveBees(Sprite beeSprites[], const int& beecount, float beeX[], float beeY[], float beeSpeedX[], bool beeAlive[],float honeycombX[],float honeycombY[], bool combactive[], const int& redbeecount,bool redbeecomb[],float redhoneycombX[],float redhoneycombY[]) {

	for (int i = 0; i < beecount; ++i) {

		//if (!beeAlive[i]) continue;
		if (beeAlive[i]) {
			beeX[i] += beeSpeedX[i];

			if (beeX[i] <= 0 || beeX[i] >= resolutionX - 32) { // Assuming bee sprite width is 32
				beeSpeedX[i] = -beeSpeedX[i]; // Reverse direction
				beeY[i] += 30; 
			}
			
			 if (beeY[i] >= resolutionY - boxPixelsY) { // Assuming bee height equals `boxPixelsY`
         		 	beeAlive[i] = false; // Mark as inactive
        		}
			
			for (int j = 0; j < beecount; ++j) {
			
               		if (combactive[j]) { 	// Only check against active honeycombs
               		
		            if (beeX[i] < honeycombX[j] + boxPixelsX && 
		                beeX[i] + boxPixelsX > honeycombX[j] &&
		                beeY[i] < honeycombY[j] + boxPixelsY &&
		                beeY[i] + boxPixelsY > honeycombY[j]) {

                        // Reverse direction and move to the next line
                        beeSpeedX[i] = -beeSpeedX[i];
                        beeY[i] += 30;
                    }
                }
            }
            		for (int j = 0; j < redbeecount; ++j) {
                if (redbeecomb[j]) { // Only check against active red honeycombs
                    if (beeX[i] < redhoneycombX[j] + boxPixelsX && 
                        beeX[i] + boxPixelsX > redhoneycombX[j] &&
                        beeY[i] < redhoneycombY[j] + boxPixelsY &&
                        beeY[i] + boxPixelsY > redhoneycombY[j]) {

                        // Reverse direction and move to the next line
                        beeSpeedX[i] = -beeSpeedX[i];
                        beeY[i] += 30;
                    }
                }
            }

			if (beeSpeedX[i] < 0) {
				beeSprites[i].setScale(1, 1);
			}
			else {
				beeSprites[i].setScale(-1, 1);
			}


			beeSprites[i].setPosition(beeX[i], beeY[i]);

		}
		
	}
}

//For Killer Bees

void moveRedBees(Sprite killerbeeSprites[], const int& redbeecount, float redbeeX[], float redbeeY[], float redbeeSpeedX[], bool redBeeAlive[],float honeycombX[],float honeycombY[], bool combactive[], const int& beecount,bool redbeecomb[],float redhoneycombX[],float redhoneycombY[]) {

	for (int i = 0; i < redbeecount; ++i) {

		//if (!redBeeAlive[i]) continue;
		if (redBeeAlive[i]) {
			redbeeX[i] += redbeeSpeedX[i];

			if (redbeeX[i] <= 0 || redbeeX[i] >= resolutionX - 32) { // Assuming bee sprite width is 32
				redbeeSpeedX[i] = -redbeeSpeedX[i]; // Reverse direction
				redbeeY[i] += 30; 
			}
			if (redbeeY[i] >= resolutionY - boxPixelsY) { // Assuming bee height equals `boxPixelsY`
         		 	redBeeAlive[i] = false; // Mark as inactive
        		}

			
            }


			if (redbeeSpeedX[i] < 0) {
				killerbeeSprites[i].setScale(1, 1);
			}
			else {
				killerbeeSprites[i].setScale(-1, 1);
			}


			killerbeeSprites[i].setPosition(redbeeX[i], redbeeY[i]);

		}
		
	}

//For Normal Bees

void randombees(float beeX[], float beeY[], const int& beecount, int& currentBeeCount, Clock& beeTimer, bool beeAlive[]) {

	if (currentBeeCount < beecount && beeTimer.getElapsedTime().asSeconds() > 2) {
		
		beeX[currentBeeCount] = rand() % resolutionX;
		beeY[currentBeeCount] = 0;
		//beeAlive[currentBeeCount] = true;
		currentBeeCount++;

		// Restart the timer
		beeTimer.restart();
	}
}

//For Killer bees

void randomredbees(float redbeeX[], float redbeeY[], const int& redbeecount, int& currentRedBeeCount, Clock& redBeeTimer, bool redBeeAlive[]) {

	if (currentRedBeeCount < redbeecount && redBeeTimer.getElapsedTime().asSeconds() > 4) {
		
		redbeeX[currentRedBeeCount] = rand() % resolutionX;
		redbeeY[currentRedBeeCount] = 0;
		//beeAlive[currentBeeCount] = true;
		currentRedBeeCount++;

		// Restart the timer
		redBeeTimer.restart();
	}
}


void checkCollision(bool& bullet_exists, float& bullet_x, float& bullet_y, float beeX[], float beeY[], int& currentBeeCount, float beeWidth, float beeHeight, bool beeAlive[], bool combactive[],float honeycombX[],float honeycombY[], int& score) {

	for (int i = 0; i < currentBeeCount; i++) {

		if (beeAlive[i]) {

			if (bullet_exists && bullet_x < beeX[i] + boxPixelsX &&
				bullet_x + boxPixelsX > beeX[i] &&
				bullet_y < beeY[i] + boxPixelsY &&
				bullet_y + boxPixelsY > beeY[i]) {

				beeAlive[i] = false;
				bullet_exists = false;
				
				combactive[i] = true;
                		honeycombX[i] = beeX[i];
                		honeycombY[i] = beeY[i];
                		
                		score += 100;
				
			}
		}
	}
}


void checkcombCollision(bool& bullet_exists, float& bullet_x, float& bullet_y, float honeycombX[], float honeycombY[], int& currentBeeCount, float beeWidth, float beeHeight, bool combactive[]) {

	for (int i = 0; i < currentBeeCount; i++) {

		if (combactive[i]) {

			if (bullet_exists && bullet_x < honeycombX[i] + boxPixelsX &&
				bullet_x + boxPixelsX > honeycombX[i] &&
				bullet_y < honeycombY[i] + boxPixelsY &&
				bullet_y + boxPixelsY > honeycombY[i]) {

				bullet_exists = false;
				
				combactive[i] = false;
                		
				
			}
		}
	}
}






void redBeeCollision(bool& bullet_exists, float& bullet_x, float& bullet_y, float redbeeX[], float redbeeY[], int& currentRedBeeCount, float beeWidth, float beeHeight, bool redBeeAlive[],bool redbeecomb[],float redhoneycombX[], float redhoneycombY[], int& score, int gamelevel) {

	for (int i = 0; i < currentRedBeeCount; i++) {

		if (redBeeAlive[i]) {

			if (bullet_exists && bullet_x < redbeeX[i] + boxPixelsX &&
				bullet_x + boxPixelsX > redbeeX[i] &&
				bullet_y < redbeeY[i] + boxPixelsY &&
				bullet_y + boxPixelsY > redbeeY[i]) {

				redBeeAlive[i] = false;
				bullet_exists = false;
				
				redbeecomb[i] = true;
                		redhoneycombX[i] = redbeeX[i];
                		redhoneycombY[i] = redbeeY[i];
                		
                		score += 1000;
                		
				
			}
		}
	}
}

void redCombCollision(bool& bullet_exists, float& bullet_x, float& bullet_y, float redhoneycombX[], float redhoneycombY[], int& currentRedBeeCount, float beeWidth, float beeHeight,bool redbeecomb[]) {

	for (int i = 0; i < currentRedBeeCount; i++) {

		if (redbeecomb[i]) {

			if (bullet_exists && bullet_x < redhoneycombX[i] + boxPixelsX &&
				bullet_x + boxPixelsX > redhoneycombX[i] &&
				bullet_y < redhoneycombY[i] + boxPixelsY &&
				bullet_y + boxPixelsY > redhoneycombY[i]) {

				//redBeeAlive[i] = false;
				bullet_exists = false;
				
				redbeecomb[i] = false;
                		//redhoneycombX[i] = redbeeX[i];
                		//redhoneycombY[i] = redbeeY[i];
				
			}
		}
	}
}


void flowering(float beeY[], int& currentBeeCount, int& currentFlowerCount, const int& maxFlowers, float flowerX[], float flowerY[], Sprite flowerSprites[], bool flowerCollisionCheck[], float groundY, int& currentRedBeeCount, float redbeeY[]) {
    
    for (int i = 0; i < currentBeeCount + currentRedBeeCount; ++i) {
     
        // Check if the bee has reached the ground level and hasn't already pollinated
     
        if (beeY[i] >= groundY - 32 && !flowerCollisionCheck[i]) { 
     
            // Bee is at the ground level (adjusted with sprite height of 32px)
     
            if (currentFlowerCount < maxFlowers) {
                // Create a new flower
                flowerX[currentFlowerCount] = rand() % (resolutionX - 50); // Random X-position for the flower
                flowerY[currentFlowerCount] = groundY - 20;                // Place the flower just above the ground
                flowerSprites[currentFlowerCount].setPosition(flowerX[currentFlowerCount], flowerY[currentFlowerCount]);

                // Mark the bee as having pollinated

                flowerCollisionCheck[i] = true;

                // Increment the current flower count
                currentFlowerCount++;
            }
        }
    
        // Check if the bee has reached the ground level and hasn't already pollinated
        if (redbeeY[i] >= groundY - 32 && !flowerCollisionCheck[i]) { 
            // Bee is at the ground level (adjusted with sprite height of 32px)
            if (currentFlowerCount < maxFlowers) {
                // Create a new flower
                flowerX[currentFlowerCount] = rand() % (resolutionX - 50); // Random X-position for the flower
                flowerY[currentFlowerCount] = groundY - 20;                // Place the flower just above the ground
                flowerSprites[currentFlowerCount].setPosition(flowerX[currentFlowerCount], flowerY[currentFlowerCount]);

                // Mark the bee as having pollinated
                
                flowerCollisionCheck[i] = true;

                // Increment the current flower count
                currentFlowerCount++;
            }
        }
    }
}



void checkCanCollision(float& player_x, float& player_y, const float& boxPixelsX, const float& boxPixelsY, int& currentFlowerCount, float flowerX[], float flowerY[], int resolutionX) {

    for (int i = 0; i < currentFlowerCount; ++i) {

       
        if (player_x < flowerX[i] + boxPixelsX && player_x + boxPixelsX > flowerX[i] &&
            player_y < flowerY[i] + boxPixelsY && player_y + boxPixelsY > flowerY[i]) {
            
           
            bool canMoving = false;

            if (player_x + boxPixelsX < resolutionX) {
                bool freeSpace = true;
                for (int j = 0; j < currentFlowerCount; ++j) {
                    if (player_x + boxPixelsX < flowerX[j] + boxPixelsX && 
                        player_x + 2 * boxPixelsX > flowerX[j]) {
                        freeSpace = false; // Space to the right is blocked
                        break;
                    }
                }
                if (freeSpace) {
                    player_x += boxPixelsX; // Move right
                    canMoving = true;
                }
            }

            if (!canMoving && player_x - boxPixelsX > 0) {
                bool freeSpace = true;
                for (int j = 0; j < currentFlowerCount; ++j) {
                    if (player_x - boxPixelsX < flowerX[j] + boxPixelsX && 
                        player_x > flowerX[j]) {
                        freeSpace = false; 
                        break;
                    }
                }
                if (freeSpace) {
                    player_x -= boxPixelsX; // Move left
                    canMoving = true;
                }
            }

            if (!canMoving) {
                cout << "Spray can is completely blocked!" << endl;
            }

            break; 
        }
    }
}


void drawFlowers(RenderWindow& window, int& currentFlowerCount, Sprite flowerSprites[], bool flowerCollisionCheck[]) {
	for (int i = 0; i < currentFlowerCount; ++i) {
	
		if(flowerCollisionCheck[i])
			window.draw(flowerSprites[i]);
	}
}

void displayScore(RenderWindow& window, Font& font, int& score) {
	Text scoreText("" + to_string(score), font, 40);
	scoreText.setPosition(850, 590);
	scoreText.setFillColor(Color::Black);
	window.draw(scoreText);
}

void moveHummingbird(bool& hummingbirdActive, float& hb_x, float& hb_y, float hb_speed, 
                     float honeycombX[], float honeycombY[], bool combactive[], int beecount, 
                     Sprite& birdSprite, Clock& stayClock, float stayTime, 
                     float redhoneycombX[], float redhoneycombY[], bool redbeecomb[], int redbeecount, int& score) {
    
    
    int targetIndex = -1; 
    int redTargetIndex = -1; 
    
    
    for (int i = 0; i < beecount; ++i) {
        if (combactive[i]) {
            targetIndex = i;
            break;  
        }
    }

   
    for (int i = 0; i < redbeecount; ++i) {
        if (redbeecomb[i]) {
            redTargetIndex = i;
            break; 
        }
    }

   
    if (targetIndex == -1 && redTargetIndex == -1) {
        hummingbirdActive = false;
        return;
    }

    
    hummingbirdActive = true;

    float targetX = 0;
    float targetY = 0;

    if (targetIndex != -1) {
        targetX = honeycombX[targetIndex];
        targetY = honeycombY[targetIndex];
    }
    else if (redTargetIndex != -1) {
        targetX = redhoneycombX[redTargetIndex];
        targetY = redhoneycombY[redTargetIndex];
        
    }

    if (hb_x < targetX) hb_x += hb_speed; // Move right
    if (hb_x > targetX) hb_x -= hb_speed; // Move left
    if (hb_y < targetY) hb_y += hb_speed; // Move down
    if (hb_y > targetY) hb_y -= hb_speed; // Move up

    
    if ((hb_x < targetX + 5 && hb_x > targetX - 5) && (hb_y < targetY + 5 && hb_y > targetY - 5)) {
    
           
        if (stayClock.getElapsedTime().asSeconds() < stayTime) {
          
            birdSprite.setPosition(hb_x, hb_y);
            return; 
        }

        if (targetIndex != -1) {
            combactive[targetIndex] = false;  
        }
        if (redTargetIndex != -1) {
            redbeecomb[redTargetIndex] = false;  
        }


      
        stayClock.restart();
    }

    
    birdSprite.setPosition(hb_x, hb_y);
}



void checkHummingbirdCollision(float honeycombX[], float honeycombY[], bool combactive[], 
                                int& score, int beecount, float hb_x, float hb_y, 
                                float redhoneycombX[], float redhoneycombY[], bool redbeecomb[], int redbeecount) {

    for (int i = 0; i < beecount; ++i) {
        if (combactive[i] && hb_x < honeycombX[i] + boxPixelsX && hb_x + boxPixelsX > honeycombX[i] &&
            hb_y < honeycombY[i] + boxPixelsY && hb_y + boxPixelsY > honeycombY[i]) {

            int tier = static_cast<int>(honeycombY[i] / (resolutionY / 8)) + 1;
            
            if (tier <= 2) score += 2000;  // Red honeycomb, top two tiers
        
            else if (tier <= 5) score += 1800; // Red honeycomb, third to fifth tiers
        
            else score += 1500; // Red honeycomb, remaining tiers

            combactive[i] = false; // Mark the honeycomb as eaten
            break;
        }
    }

    for (int i = 0; i < redbeecount; ++i) {
        if (redbeecomb[i] && hb_x < redhoneycombX[i] + boxPixelsX && hb_x + boxPixelsX > redhoneycombX[i] &&
            hb_y < redhoneycombY[i] + boxPixelsY && hb_y + boxPixelsY > redhoneycombY[i]) {

            int tier = static_cast<int>(redhoneycombY[i] / (resolutionY / 8)) + 1;
           
            if (tier <= 2) score += 1000;  // Regular honeycomb, top two tiers
        
            else if (tier <= 5) score += 800; // Regular honeycomb, third to fifth tiers
        
            else score += 500; // Regular honeycomb, remaining tiers
        

            redbeecomb[i] = false; // Mark the red honeycomb as eaten
            break;
        }
    }
}


void checkHummingbirdSick(bool& bullet_exists, float bullet_x, float bullet_y, float hb_x, float hb_y, bool& hummingbirdActive, Clock& hbClock) {

    if (!hummingbirdActive) return;

    if (bullet_exists && bullet_x < hb_x + boxPixelsX && bullet_x + boxPixelsX > hb_x &&
        bullet_y < hb_y + boxPixelsY && bullet_y + boxPixelsY > hb_y) {

        hummingbirdActive = false;  
        hbClock.restart();  
        bullet_exists = false; 
    }
}

void renderHummingbird(RenderWindow& window, bool& hummingbirdActive, Sprite& birdSprite) {
    if (hummingbirdActive) {
        window.draw(birdSprite);  
    }
}

void checkBeehiveCollision(float bullet_x, float bullet_y, bool& bullet_exists, 
                           const float boxPixelsX, const float boxPixelsY, 
                           bool hiveActive[], float hiveX[], float hiveY[], const int preGenBeeHive) {
    
    for (int i = 0; i < preGenBeeHive; i++) {
        
        if (hiveActive[i]) { 
            
            if (bullet_exists && bullet_x < hiveX[i] + boxPixelsX && bullet_x + boxPixelsX > hiveX[i] &&
                bullet_y < hiveY[i] + boxPixelsY && bullet_y + boxPixelsY > hiveY[i]) {
                
                hiveActive[i] = false;  
                bullet_exists = false; 
            }
        }
    }
}



void preGenHoneyCombs(float honeycombX[], float honeycombY[], const int preGenComb,bool combactive[]) {
    
    for (int i = 0; i < preGenComb; i++) {
    
        honeycombX[i] = rand() % (resolutionX - boxPixelsX);  
        honeycombY[i] = rand() % (resolutionY - 100);         
      
        combactive[i] = true;  
    }
}
void renderPreGenComb(RenderWindow& window, Sprite& honeycombSprite, float honeycombX[], float honeycombY[], bool combactive[], const int preGenComb) {
    
    for (int i = 0; i < preGenComb; i++) {
    
        if (combactive[i]) {
    
            honeycombSprite.setPosition(honeycombX[i], honeycombY[i]);
            window.draw(honeycombSprite);
        }
    }
}

void transitionLevel(RenderWindow& window, int gamelevel) {
    Font font;
    if (!font.loadFromFile("Fonts/arial.ttf")) {
        cout << "Error: Could not load font!" << endl;
        return;
    }

    Text transitionMessage("Level Complete! Move to Level " + to_string(gamelevel + 1), font, 50);
    transitionMessage.setPosition(resolutionX / 2 - 300, resolutionY / 2 - 50);
    transitionMessage.setFillColor(Color::Yellow);

    window.clear();
    window.draw(transitionMessage);
    window.display();

    // Wait for 2 seconds before transitioning to the next level
    
    Clock clock;
    while (clock.getElapsedTime().asSeconds() < 2) {}
}

void gameOver(RenderWindow& window) {
    Font font;
    if (!font.loadFromFile("Fonts/arial.ttf")) {
        cout << "Error: Could not load font!" << endl;
        return;
    }

    Text gameOverMessage("Game Over! You Win!", font, 50);
    gameOverMessage.setPosition(resolutionX / 2 - 200, resolutionY / 2 - 50);
    gameOverMessage.setFillColor(Color::Yellow);

    window.clear();
    window.draw(gameOverMessage);
    window.display();

    // Wait for 5 seconds before closing the game
    
    Clock clock;
    while (clock.getElapsedTime().asSeconds() < 5) {}
}

bool checkLevelComplete(int& score, bool beeAlive[], bool combactive[], int beecount, int redbeecount, bool redbeecomb[], bool redBeeAlive[]) {
                        
    bool noBeesAlive = true;
    for (int i = 0; i < beecount; ++i) {
        if (beeAlive[i]) {
            noBeesAlive = false;
            break;  
        }
    }
    for (int i = 0; i < redbeecount; ++i) {
        if (redBeeAlive[i]) {
            noBeesAlive = false;
            break;  
        }
    }

    
    bool noHoneycombsActive = true;
    for (int i = 0; i < beecount; ++i) {
        if (combactive[i]) {
            noHoneycombsActive = false;
            
        }
    }

    for (int i = 0; i < redbeecount; ++i) {
        if (redbeecomb[i]) {
            noHoneycombsActive = false;
            
        }
    }

    return (noBeesAlive && noHoneycombsActive)	; 
}


////////////////////////////////////////////////

//		Phase 2

////////////////////////////////////////////////


void preGenBeeHives(float hiveX[], float hiveY[], const int preGenBeeHive, bool hiveActive[]) {
    for (int i = 0; i < preGenBeeHive; i++) {
      
        hiveX[i] = rand() % (resolutionX - boxPixelsX);  
        hiveY[i] = rand() % (resolutionY - 200) + 100; 
        hiveActive[i] = true;  
    }
}

void renderPreGenBeeHives(RenderWindow& window, Sprite hiveSprites[], float hiveX[], float hiveY[], bool hiveActive[], const int preGenBeeHive) {

    for (int i = 0; i < preGenBeeHive; i++) {
    
        if (hiveActive[i]) {  // Only render active hives
            hiveSprites[i].setPosition(hiveX[i], hiveY[i]);
            window.draw(hiveSprites[i]);                   
        }
    }
}



