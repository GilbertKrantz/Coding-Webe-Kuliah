// Login a User
// API Path : /api/Users/Login

function validateForm() {
    var email = document.forms["login-form"]["Email"].value;
    var password = document.forms["login-form"]["password"].value;
   
    if (email == "" || !validateEmail(email)) {
       alert("Please enter a valid email address");
       return false;
    }
    
    // Password must have 1 symbol, 1 character, 1 number
    var re = /(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{8,}/;
    if (password == "" || password.length < 8 || !re.test(password)) {
       alert("Password must be at least 8 characters long");
       return false;
    }
   
    return true;
}
   
function validateEmail(email) {
    var re = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/;
    return re.test(email);
}

    // Method : POST
    document.getElementById("login-form").addEventListener("submit", function (event) {
        event.preventDefault();

        if (!validateForm()) {
            return false;
        } 
    
        let email = document.getElementById("Email").value;
        let password = document.getElementById("password").value;
    
        // console.log(email, password);
    
        var xhr = new XMLHttpRequest();
        xhr.open("POST", "https://localhost:7253/api/Users/Login", true);
        xhr.setRequestHeader('Content-Type', 'application/json;charset=UTF-8');
    
        // console.log(xhr.responseText);
    
        xhr.onreadystatechange = function() {
            if (xhr.readyState === 4 && xhr.status === 200) {
                let response = JSON.parse(xhr.responseText);
                localStorage.setItem("token", response.token);
                localStorage.setItem("name", response.name);
                localStorage.setItem("id", response.userId);
                localStorage.setItem("email", response.email);
                localStorage.setItem("role", response.role);
                localStorage.setItem("isLoggedIn", true);
                window.location.href = "Dashboard.html";
            } else if (xhr.readyState === 4 && xhr.status === 400) {
                showPopup('Invalid Credentials!');
            }
        };
        // console.log(xhr.status);
    
        var data = JSON.stringify({
            email: email,
            password: password
        });
    
        xhr.send(data);
    })
