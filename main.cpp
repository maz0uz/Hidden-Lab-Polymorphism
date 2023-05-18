//
//  main.cpp
//  CS2 Hidden Lab - Polymorphism
//
//  Created by Mohamed Azouz on 18/05/2023.
//

#include <iostream>
using namespace std;

#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel {
private:
    string Name;
    int SubscribersCount;
    list<string> PublishedVideoTitles;
    // write a paragraph about the list data strucutre above, its usage, and the main methods that can be used on it.
    /*
     A list is a linear data structure that stores elements in a sequential manner. Unlike arrays or vectors, a list does not provide direct access to its elements by index. Instead, it maintains a doubly linked list structure where each element, called a node, contains a value and two pointers: one pointing to the previous node and another to the next node. A list is very useful for data sets which require a lot of data insertion or deletion.
     Some useful functions are:
     
     push_back which adds a value to the end of the list
     push_front which addds a value to the front of the list
     pop_back and pop_front which remove elements from the back and front of the list
     size which returns the number of elements in the list
     */
protected:
    string OwnerName;
    int contentQuality;
public:
    YouTubeChannel(string name, string ownerName) {
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
        contentQuality = 0;
    }
    void GetInfo() {
        cout << "Name: " << Name << endl;
        cout << "OwnerName: " << OwnerName << endl;
        cout << "SubscribersCount: " << SubscribersCount << endl;
        cout << "Videos: " << endl;
        for (string videoTitle : PublishedVideoTitles) {
            cout << videoTitle << endl;
        }
    }
    void Subscribe() {
        SubscribersCount++;
    }
    void Unsubscribe() {
        if (SubscribersCount > 0)
            SubscribersCount--;
    }
    void PublishVideo(string title) {
        PublishedVideoTitles.push_back(title);
    }
    // create void RateContent that prints a content is good if the quality is above 5, bad otherwise.
     void RateContent()
    {
         if(contentQuality>5)
             cout<<"content is good"<<endl;
         else
             cout<<"content is bad"<<endl;
     }
    
};

class CookingYouTubeChannel :public YouTubeChannel {
public:
    CookingYouTubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName) {

    }
    void Practice() {
        cout << OwnerName << " is practicing cooking, learning new recipes, experimenting with spices..." << endl;
        contentQuality++;
    }
};

class SingersYouTubeChannel :public YouTubeChannel {
public:
    SingersYouTubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName) {

    }
    void Practice() {
        cout << OwnerName << " is taking singing lessons, learning new music, experimenting with tunes..." << endl;
        contentQuality++;
    }
};
 
int main()
{
    CookingYouTubeChannel cook("Ali's Kitchen", "Ali");
    SingersYouTubeChannel sing("Rana's Studio", "Rana");
    
    
    cook.Practice();  // Call the Practice() function on the 'cook' object (CookingYouTubeChannel).
    sing.Practice();  // Call the Practice() function on the 'sing' object (SingersYouTubeChannel).
    // the practice functions are different on both objects becase they are 2 different classes which inherit from the same class.
    
    cook.RateContent();  // Call the RateContent() function on the 'cook' object (CookingYouTubeChannel).
    sing.RateContent();  // Call the RateContent() function on the 'sing' object (SingersYouTubeChannel).
    
    //the ratecontent function is present only in the parent class of the two different objects. They share the same parent so the ratecontent function is the same for both.

    
    return 0;
}
