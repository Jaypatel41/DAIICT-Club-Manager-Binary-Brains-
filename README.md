# DA-IICT Club Manager

## Summary

A Console Based Club Manager which assist club Handlers to maintain club infomations this Manager provides services of Events Handling , Convenors Table and Club members Details. this manager is created to case insensity in choices.

## Functionality Provided By Manager:

1. **Event Heading**
   This section can be accesed in 2 mode admin/viewer only admin mode has a feature of Create new events or Deletion of event and Viewer mode can Look for Upcoming Events list at DA-IICT

2. **Club Handling**
   Manager provides Functionality to create or remove an Existing club also this feature is Password protected and be accesed in admin mode. Manager also Maintains List of Current club Converors. 

3. **Club Details Heading**
Details of existing Club Members can be changed, or a new member can be created,the input name of member are also case insensity which provides user to get Flexibility entering name - surname , methods of searching of a member include search by name/search by name/search of all members of a club/ search of all Members of a Club Category 

## Member Functions 

1. **Search Of Member:**
searching of a member in given club is much less then o(n) as details are stored in form of hash tables 
search of club is o(1) and club category is also o(1) search by name function is also provided.

2. **Additional Of Member:**
Addition of a member into any club is done by insertion function which creates a entity in hash table and user name is independent of capitalCase / lowerCase and stores name - surname. 

3. **Deletion Of Member:**
Deletion of a member can be done from any particular and allows member to be in other distinct clubs

4. **Event Scheduling:**
   This Provides Calender of events organised by clubs and have functionality to create or remove any event this needs proper login creditial to perform

## Error Heading

- No Member is overloaded in a particular club insertion only can be done on existing clubs
- Deletion of any member can be performed by checking if member is existing or not
- searching of a member by its id shows all the list of clubs that member is a part of.
- searching by name of a member shows all members of same name different IDs.
- In case of searching or entering name errors of undefined clubs is included.  
- Club Deletion is possible for clubswhich are defined.
- Addition of club includes no overloading of clubs
- Convenors of Clubs can be only performed if the Member Exist in that particular club.
- Events-Convenors-Club formation are protected functions
  
## IMPORTANT

Our Code is totally working . Firstly, we guys have divided work and made separate functions and committed in Github but in last when we made main function then there holds a issue of header files. So now we guys have summarised the whole code in main function.(main.cpp)


Output PDF link is given below which contains all error and edge case explaination.

[DOCUMENT FILE](https://docs.google.com/document/d/18OPZXEhLvjTLeWrgIQLb0bM5644VFAxHb7ieCvH2bWY/edit)

[OUTPUT PDF](https://drive.google.com/file/d/1Q8Vb8oSqEhFjU0tBaLRqitrRJ2p6lCQ6/view?usp=sharing) 

**Student Detail**

- Dhyey Patel : 202301415
- Jay Patel : 202301430
- Dushyant Varshney : 202301278
- Pratik Chauhan : 202301430
