1. 
    a. Ruby Link
    b. 2392068
    c. rlink@chapman.edu
    d. cpsc 231-02
2. MP4 Music App
3. Account.java, Artist.java, Listener.java, Content.java, Song.java, Podcast.java, ContentCollentions.java, Playlist.java, Album.java, Driver.java, favor.txt
4. No run-time errors that I know of. 
5. Used class notes and office hours to help complete the code. Anoushka Sarma also helped me map out the hierarchy.  

6. For my project, I split up the classes into three main families. The first is Account, with child classes Artist and Listener. Account is an abstract class that has one member variable, m_username, and passes this along to its child classes. Artist has no member variables of its own, but extends from Account’s. Listener has its own private member variable, m_content, and has two of its own methods to create and retrieve the listeners favorites. Next, Content, an abstract class with child classes Song and Podcast, has three member variables (m_title, m_artist, m_numStreams). It has an equals() method and a compareTo() method to track if two pieces of content are equal and how many times they have been played. It also implements the Comparable interface. Song and Podcast inherit these attributes. Song has a play() method which overrides the original in Content. Podcast has an additional member variable, m_numEpisode, and an accessor for it. It also overloads the equals() method and like Song, overrides the play() method. Finally, ContentCollections is also abstract and implements the Comparable interface. It has member variables m_collectionName and m_collect. With the Comparable interface, it has a compareTo() method. It also has the abstract method, playCollect(). Its two child classes, Playlist and Album inherit these attributes, and create no additional member variables. Playlist has its own method, shuffle(), which is called in the overridden method, playCollect() to play an entire Playlist until all Content has been played. It also has two additional methods to add a Podcast or Song to the Playlist. It also has its own toString method which overloads the parent class’. The Album class overrides playCollect() to play everything in an Album and overloads the toString method. 

I chose this particular structure because everything is grouped together in a way that makes sense. Each child class extends from a parent class that has shared variables in order to create an instance of that class. It is the most efficient way because I didn’t have to recreate member variables or inherited methods as they were automatically passed on. 

I faced most of my challenges in the Driver. I had trouble coming up with a way to add already created songs into favorites. When I asked the user to name a song, I would just create a new object each time, but this way, it wouldn’t keep track of the number of times it had been played. I remedied this by using my equals method to check to see if the song the user wants to add is already in a playlist or an album. If it is, I just use the previously created object as a favorite instead of creating a new instance. 

I think that a future developer could add a Spotify Wrapped type idea. You could keep track of the favorites, the number of songs played in total, who the top artists are, and the top genres. I would also add more ways to sort songs and podcasts, like by the duration of the song/podcast.


