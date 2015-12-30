// Variables
int isOpen = 0;
int useCount = 0;
int buttonState = 0;
int lastButtonState = 0;
char userName[100];

// Functions
int openCloseGarage(String string);
int updateName(String name);
int incrementUse(String string);

// Pins
int led1 = D1;

void setup() {
    
    // Variables
    Particle.variable("isopen", &isOpen, INT);
    Particle.variable("usecount", &useCount, INT);
    Particle.variable("username", userName, STRING);
    
    // Functions
    Particle.function("openclose", openCloseGarage);
    Particle.function("updatename", updateName);
    Particle.function("incrementuse", incrementUse);
    
    // Pins
    pinMode(D1, INPUT);
}

void loop() {
    
     // read the pushbutton
    buttonState = digitalRead(D1);

    // compare the buttonState to its previous state
    if (buttonState != lastButtonState) {
        // if the state is HIGH, it measn it was pressed
        if (buttonState == HIGH) {
           // Update the name. 
           updateName("Remote");
           
           // Increment the use
           incrementUse("");
           
           // Update the isOpen state
           isOpen = !isOpen;
        }
        
        // save the current state as the last state,
        // for future reference
        lastButtonState = buttonState;
    }
}

int openCloseGarage(String string) {
    
    isOpen = !isOpen;
    
    pinMode(D1, OUTPUT);
    digitalWrite(D1, HIGH);
    
    delay(500);
    pinMode(D1, INPUT);
    
    return 0;
}

int updateName(String name) {
    
    strcpy(userName, name.c_str());
    
    return 0;
}

int incrementUse(String string) {
    
    useCount++;
    
    return 0;
}
