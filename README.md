This is the final project of James Raynard's Udemy course, named "Take your knowledge of C++ to the next level!"

The instructor uses SFML 2.5, I used SFML 3.0.0
  One major change is that sf::Sprite class has lost its default (no args) constructor, and now it requires a sf::Texture object to initialize
  Solution: 
    1) make a static sf::Texture member inside the "entity" class, which is the abstract base class of all objects in the program
    2) load the appropriate image into the texture member in constructors
    3) initialize the sprite object with the texture member passed into the argument

