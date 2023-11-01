
if (isLoggedIn === "true") {

// Open popup when clicked on add category button
let addCategoryButton = document.getElementById("add-categories-btn");
if (addCategoryButton) {
    addCategoryButton.addEventListener("click", function () {
        document.getElementById("add-categories-popup").style.display = "block";
    });
}


// Close popup when clicked outside or on close button
let closeCategoryPopup = document.getElementById("close-categories-popup");
if (closeCategoryPopup) {
    closeCategoryPopup.addEventListener("click", function () {
        document.getElementById("add-categories-popup").style.display = "none";
    });
}

// Add category
document.getElementById("add-categories-form").addEventListener("submit", function (event) {
    event.preventDefault();

    let userId = localStorage.getItem("id");
    let categoryName = document.getElementById("category-name").value;

    var xhr = new XMLHttpRequest();
    xhr.open("POST", "https://localhost:7253/api/Users/NewCategory", true);
    xhr.setRequestHeader('Content-Type', 'application/json;charset=UTF-8');

    console.log(userId, categoryName);

    xhr.onreadystatechange = function () {
        if (xhr.readyState === 4 && xhr.status === 200 || xhr.status === 201) {
            document.getElementById("add-categories-popup").style.display = "none";
            console.log(xhr.responseText);
        }
    };

    xhr.send(JSON.stringify({
        UserId: userId,
        CategoryName: categoryName
    }));
});

// Show categories from categories table in warehouse database using jquery
let i = 1;
$(document).ready(function () {
    $.ajax({
        url: "https://localhost:7253/api/Users/GetCategories",
        method: "GET",
        success: function (result) {
            console.log(result);
            let categories = "";
            for (let category of result) {
                console.log(category);
                categories += `
                <tr>
                    <td>${i++}</td>
                    <td>${category.categoryName}</td>
                    <td><button class="btn btn-warning" onclick="editCategory(${category.categoryId})">Edit</button>
                    <button class="btn btn-danger" onclick="deleteCategory(${category.CategoryId})">Delete</button></td>
                </tr>
                `;
            }
            $("#categories").append(categories);
        }
    });
});

// Edit category
function editCategory(categoryId) {
    // console.log(categoryId);
    document.getElementById("edit-categories-popup").style.display = "block";

    document.getElementById("edit-categories-form").addEventListener("submit", function (event) {
        event.preventDefault();

        let categoryName = document.getElementById("edit-category-name").value;

        var xhr = new XMLHttpRequest();
        xhr.open("PUT", `https://localhost:7253/api/Users/PutCategory/${categoryId}`, true);
        xhr.setRequestHeader('Content-Type', 'application/json;charset=UTF-8');

        // console.log(categoryName, categoryId);

        xhr.onreadystatechange = function () {
            if (xhr.readyState === 4 && xhr.status === 200 || xhr.status === 201) {
                document.getElementById("edit-categories-popup").style.display = "none";
                console.log(xhr.responseText);
            }
        };

        xhr.send(JSON.stringify({
            CategoryName: categoryName
        }));
    });
}

// Delete category
function deleteCategory(categoryId) {
    // console.log(categoryId);

    document.getElementById("categories").addEventListener("click", function (event) {
        event.preventDefault();
        var xhr = new XMLHttpRequest();
        xhr.open("DELETE", `https://localhost:7253/api/Users/DeleteCategory/${categoryId}`, true);
        xhr.setRequestHeader('Content-Type', 'application/json;charset=UTF-8');
    
        xhr.onreadystatechange = function () {
            if (xhr.readyState === 4 && xhr.status === 200 || xhr.status === 201) {
                console.log(xhr.responseText);
            }
        };
    
        xhr.send();
    });
}} else {
    window.location.href = "login.html";
}