// Show User on Header using Local Storage

// Get the user from local storage
let user = localStorage.getItem("name");
let isLoggedIn = localStorage.getItem("isLoggedIn");
let role = localStorage.getItem("role");

// Get the element from the DOM
let userElement = document.getElementById("user");
let loginElement = document.getElementById("login");

// Check if user is logged in
if (isLoggedIn === "true") {
    // Show the user name
    userElement.innerHTML = user;
    // Show the logout button
    loginElement.innerHTML = "Logout";
    loginElement.setAttribute("href", "logout.html");
    // Hide register button
    document.getElementById("register").style.display = "none";
} else {
    // Show the login button
    loginElement.innerHTML = "Login";
    loginElement.setAttribute("href", "login.html");
}

// Logout a User
document.getElementById("login").addEventListener("click", function (event) {
    event.preventDefault();
    
    let isLoggedIn = localStorage.getItem("isLoggedIn");

    if (isLoggedIn === "true") {
        localStorage.clear();
        window.location.href = "login.html";
    } else { 
        window.location.href = "login.html";
    }
});