var tweetURL = "";
var tempList = "";
var randomQuote = "";
var html = "";
var quoteBody = document.querySelector("#quote-body");
var quote = document.querySelector("#quote");
var button = document.querySelector("#quote-btn");
var share = document.querySelector("#share");


// Object with quotes & authors
var quotes = [
    { 
  text: "A winner never quits and a quitter never wins ." ,
  author: "- Gaurav Keswani -"
 },
 { 
  text: "Design is not for philosophy it's for life.",
  author: "- Issey Miyake -"
 },
 {
  text: "You cannot have a positive life and a negative mind.",
  author: "- Joyce Meyer -"
 },
 { 
  text: "The true sign of intelligence is not knowledge, but imagination." ,
  author: "- Albert Enstein -"
 },
 { 
  text: "Do what you can, with what you have, where you are.", 
  author: "- Theodore Roosevelt -"
 },
 { 
  text: "The journey of a thousand miles begins with one step.", 
  author: "- Lao Tzu -"
 },
 { 
  text: "Don't cry because it's over. Smile because it happened.", 
  author: "- Dr.Seuss -"
 },
 { 
  text: "It always seems impossible until its done." ,
  author: "- Nelson Mandela -"
 }
 ]


// Shuffle the quotes  
function randomize(){
  tempList = Object.keys(quotes);
  randomQuote = tempList[ Math.floor(Math.random() * tempList.length)];
  console.dir(randomize);
}

// Load a quote on the page
function loadQuote(){
  randomize();
  
  // Create an element to load a quote
  html = '<p id="quote"><q>' + 
          quotes[randomQuote].text + 
          '</q><span class="quote-author">' + 
          quotes[randomQuote].author + '</span></p>';
  
  // Create Tweeter URL to share a quote
  tweetURL = "https://twitter.com/intent/tweet?text=" + 
             '"' +  quotes[randomQuote].text +
             '" ' + quotes[randomQuote].author +
             ' %23wisdom ' + '%23quotes ' + '%23inspiration ';
  
  // Display element with a quote on the page
  quoteBody.innerHTML = html;
 
}
loadQuote();  
  
// Load a new random quote on click
button.onclick = function(){
   loadQuote();
}

// Open Twitter window
share.onclick = function(){
  window.open(tweetURL);
}