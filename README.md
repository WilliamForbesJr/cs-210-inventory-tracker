# CS-210 Inventory Tracker

## Project Summary
This project is designed to accept a `.txt` file containing a list of items (specifically grocery items), read its contents, write item data to a consolidated `.dat` file, and perform various actions depending on user input.

Actions include:
 - Counting the number of items on the list and presenting each item count to user.
 - Searching for a specific item based on user-entered text.
 - Generating a historgram using generated `.dat` file.
 
This program integrates both C++ and Python to accomplish the tasks. C++ handles all rendering, user interaction, and creates a runtime environment to serve as a controller for Python. Python purely manages all functionality surrounding data which includes reading and writing file contents, and creating data models based on that information to pass to C++ to render to the user.

## Sucesses
I was pleased to have been able to create a modular controller-based approach in C++. I felt that the class stucture was overall easy to digest, debug, and each class had a clear single purpose who's member functions and data members supported. I tried to take an approach to design each class with the mindset that this application could scale. With that in mind, I tried to encapsulate implementation details where necessary such as within the Python controller to abstract the Python procedures and only present the member functions which would be relevant to other classes. I was also happy with having class structure that leaves each class outside of the main controller unaware and independent from the other classes.

## Improvements
I would have loved to take a more class-based approach with the Python logic instead of exposing its functions in global scope. I also wish I stayed a little more true to using a strategy pattern and perhaps implemented abstract classes with virtual functions to create more of an interface for some of the controller logic in Python. I think that would have been a cleaner approach than encapsulation. I also should have created a singular dedicated struct or data model class for the list data returned from Python.

I feel these improvements would have helped to separate concerns a little better and clean up some of the class logic. In the case of a class approach with Python, that would have clearly also helped to harden the Python logic and expose much less data.

## Challenges
I feel that the most challenging part of this project was utilizing class pointers and referencing other classes and their functions. I wanted to be purposeful with class referencing and memory management. Unfortunately, I still encountered quite a few roadblocks with getting exceptions when referencing classes within other class constructors. I ended up taking an approach of creating a single controller that instantiates the other controller objects and dispatches all of their actions. I think it turned out fine, but I think it could have been a little cleaner to use pointers instead. I feel that my mindset was still treating C++ too much like Java or C#. I'd like to take some time to better wrap my head around C++ conventions and memory management as it's such an integral part of the language.

## Skills Gained
I absolutely feel that I have a stronger foundation for C++ than I previously had which has made reading documentation for projects utilize C++ much easier. I feel that even having a rudamentary understanding of other languages outside of your core languages is extremely valuable as you will often be working in close proximity with those various other languages. For example, as a full stack developer, being able to better understand something like C++ is really beneficial since Chromium is written primarily in that language. I also feel that I sharpened up my OOP skills a little bit by working in a language that requires a different approach and challenged myself to try and follow common conventions.
