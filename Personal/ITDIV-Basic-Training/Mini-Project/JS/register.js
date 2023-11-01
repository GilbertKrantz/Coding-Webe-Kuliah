// Objective: Register a new user

// ShowPopup function
function showPopup(message) {
    window.alert(message);
}


// function to validate name, email, password from register-form and if not valid, show popup and return false
function validateForm() {
    var name = document.forms["register-form"]["Name"].value;
    var email = document.forms["register-form"]["Email"].value;
    var password = document.forms["register-form"]["password"].value;
    var confirmPassword = document.forms["register-form"]["confirm-password"].value;
    var TnC = document.forms["register-form"]["TnC"].checked;
   
    if (name == "" || name.length < 2) {
       alert("Name must be at least 2 characters long");
       return false;
    }
   
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

    if (confirmPassword != password) {
        alert("Passwords do not match");
        return false;
    }

    if (!TnC) {
        alert("Please accept the Terms and Conditions");
        return false;
    }
   
    return true;
   }
   
   function validateEmail(email) {
    var re = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/;
    return re.test(email);
   }




document.getElementById("register-form").addEventListener("submit", function (event) {
    event.preventDefault();

    if (!validateForm()) {
        return false;
    }

    let name = document.getElementById("Name").value;
    let email = document.getElementById("Email").value;
    let password = document.getElementById("password").value;

    var xhr = new XMLHttpRequest();
    xhr.open("POST", "https://localhost:7253/api/Users/Registration", true);
    xhr.setRequestHeader('Content-Type', 'application/json;charset=UTF-8');

    xhr.onreadystatechange = function() {
        if (xhr.readyState === 4 && xhr.status === 200 || xhr.status === 201) {
            showPopup('Successfully Registered, please Login!');
            console.log(xhr.responseText);
        }
    };

    var data = JSON.stringify({
        name: name,
        email: email,
        password: password
    });

    xhr.send(data);
});