import java.util.*;
import java.io.*;
//import mismatch;

public class Driver{
  public static void main(String[] args) {

    //Create songs and podcasts
    Podcast skimmThis3 = new Podcast("SkimmThis", "HP", 3);
    Podcast theDaily48 = new Podcast("TheDaily", "NewYorkTimes", 48);
    Podcast modernLove33 = new Podcast("ModernLove", "MiaMiller", 33);
    Song valentine = new Song("Valentine", "COIN");
    Song bradPitt = new Song("BradPitt", "COIN");
    Song chapstick = new Song("Chapstick", "COIN");
    Song cutie = new Song("Cutie", "COIN");
    Song takeAPicture = new Song("TakeAPicture", "COIN");

    Listener listenAcc = new Listener("default");
    int userInput = 0;
    PrintWriter write = null;

    LinkedList<Content> playlist = new LinkedList<>();
    playlist.add(skimmThis3);
    playlist.add(theDaily48);
    playlist.add(valentine);
    playlist.add(bradPitt);

    LinkedList<Content> album = new LinkedList<>();
    album.add(valentine);
    album.add(bradPitt);
    album.add(chapstick);
    album.add(cutie);
    album.add(takeAPicture);

    Album uncannyValley = new Album("Uncanny Valley", album);
    
    Playlist rubsJams = new Playlist("rubsJams", playlist);
    
///////////////////////////////////////////////////////////////
    
    System.out.println("\nWelcome to Ruby's Music App!");
    System.out.println("\nPlease choose from one of the options below!");
    while (userInput != 7){
      //System.out.println("\nThese are your options: ");
      System.out.println("\n1. Create a listener account");
      System.out.println("2. List all Playlists and Albums and their contents");
      System.out.println("3. Add songs to an existing playlist");
      System.out.println("4. Shuffle an existing Playlist or listen to an Album");
      System.out.println("5. Add a song or podcast to favorites");
      System.out.println("6. Export all of a listener’s favorites out to a file in ascending order by times streamed");
      System.out.println("7. Exit\n");

      Scanner user = new Scanner(System.in);
      System.out.println("Please select an option: ");
      
      try {
        userInput = user.nextInt();
      }
      catch (InputMismatchException im){
        im.printStackTrace();
        System.err.println("That is not a valid input. Please enter an option number you see below: ");
      }
      
      if (userInput == 1){
        System.out.println("Give your account a name");
        String userName = user.next();
        listenAcc = new Listener(userName);
        System.out.println("Welcome " + listenAcc +"!");
      }
      else if (userInput == 2){
        System.out.println("PLAYLIST: ");
        System.out.println(rubsJams);
        System.out.println("ALBUM: ");
        System.out.println(uncannyValley);
      }
      else if (userInput == 3){
        System.out.println("What is the name of the song would you like to add? Dont enter a space inbetween words :)");
        String songTitle = user.next();
        System.out.println("Who sings it?");
        String songArtist = user.next();
        Song newSong = new Song(songTitle, songArtist);
        rubsJams.addSong(newSong);
        System.out.print("ADDED SONG: " + newSong);
      }
      else if (userInput == 4){
        System.out.println("Do you want to play a Playlist or an Album?");
        String choice = user.next();
        if(choice.equals("Album")){
          System.out.println("ALBUM PLAYED: ");
          uncannyValley.playCollect(); 
        }
        else{
          System.out.println("PLAYLIST PLAYED: ");
          rubsJams.playCollect();
        }
      }
      else if (userInput == 5){
        System.out.println("Are you adding a Song or a Podcast?");
        String choose = user.next();
        if (choose.equals("Podcast")){
          System.out.println("Which Podcast would you like to add to your Favorites?");
          System.out.println("Give the name with no spaces in between words: ");
          String podName = user.next();
          System.out.println("Give the episode title with no spaces: ");
          String podTitle = user.next();
          System.out.println("Give the episode number: ");
          int podNum = user.nextInt();
          Podcast favPod = new Podcast(podName, podTitle, podNum);
          int counter = 0;
          Content holdPod = null;
          for (Content pod: playlist){
            if (podName.equals(pod)){
              counter += 1; 
              holdPod = pod;
            }
          }
          if (counter > 0){
            listenAcc.favorite(holdPod);
          } 
          else{
            listenAcc.favorite(favPod);
            }
          System.out.println ("A podcast has been added to your favorites!");
        }
        else{
          System.out.println("Give the name with no spaces: ");
          String songName = user.next();
          System.out.println("Give the artist name with no spaces: ");
          String songArtist = user.next();
          Song favSong = new Song(songName, songArtist);
          int counter = 0;
          Content holdSong = null;
          for (Content song: album){
            if (favSong.equals(song)){
              counter += 1;
              holdSong = song;
            }
          }
          if (counter > 0){
            listenAcc.favorite(holdSong);
          }
          else{
            listenAcc.favorite(favSong);
            }
          
          System.out.println ("A song has been added to your favorites!");
    }
      }
    
      else if (userInput == 6){
        LinkedList<Content> theirFavor = listenAcc.getFavorites();
    try {
        write = new PrintWriter(new FileWriter("./favor.txt"));
        write.println("FAVORITES");
        Collections.sort(theirFavor);
        for(Content m: theirFavor){ 
          write.println(m);
        }
        write.close();   
     
    }
      catch (IOException ioe){
        System.err.println("Couldn't output to file");
        ioe.printStackTrace();
    } 
      }
    else if (userInput == 7){
      System.out.println("Thanks for listening with us!");
    }
      
    }

    

    
  
    
  
      


  }
}