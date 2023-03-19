# Data Structures & Algorithms semester project

Implementation of a social network with a simplified model, from which relevant information can be extracted.

Basic functionalities:
User management: CRUD operations.
Management of friendship relationships between users: add/delete friend
Message management: send/delete message

The entities of the problem are: user, friendship, message. A network user has a list of friends and a friendship is established between two network users. The network is defined by the number of users and the friendships between them.

To solve the problem, I implemented the following 2 data structures:

**1. ---> List of generic elements, with array representation**

I used this TAD in the definition of the generic repository (Repository.h), where I gave a generic list as a parameter
(List<T>); to implement the add, delete, size, update, find, size and getElem methods, I used the previously defined operations in the list, exactly the same as if I had worked with the VECTOR class from STL;

**2. ---> Ordered set with generic elements, with binary search tree representation**

I used this TAD in defining the repository for the EVENT class (RepoEvent.h); there I gave as a parameter the ordered set with representation on ABC, and to implement the add, remove and getAll methods I used the previously defined operations in the set.
