// Nav Bar
const navbarToggle = navbar.querySelector("#navbar-toggle");
const navbarMenu = document.querySelector("#navbar-menu");
const navbarLinksContainer = navbarMenu.querySelector(".navbar-links");
let isNavbarExpanded = navbarToggle.getAttribute("aria-expanded") === "true";

const toggleNavbarVisibility = () => {
  isNavbarExpanded = !isNavbarExpanded;
  navbarToggle.setAttribute("aria-expanded", isNavbarExpanded);
};

navbarToggle.addEventListener("click", toggleNavbarVisibility);

navbarLinksContainer.addEventListener("click", (e) => e.stopPropagation());
navbarMenu.addEventListener("click", toggleNavbarVisibility);

// Form
const contactForm = document.getElementById("contact-form");
const firstName = document.getElementById("fname");
const lastName = document.getElementById("lname");
const email = document.getElementById("email");
const phone = document.getElementById("phone");

const inquiry = document.getElementsByName("inquiry");

const message = document.getElementById("inquiry-desc");

const submitButton = document.getElementById("submit-btn");

const validateForm = () => {
  let isValid = true;
  if (firstName.value === "") {
    firstName.setCustomValidity("Please enter your first name.");
    isValid = false;
  } else {
    firstName.setCustomValidity("");
  }

  if (lastName.value === "") {
    lastName.setCustomValidity("Please enter your last name.");
    isValid = false;
  } else {
    lastName.setCustomValidity("");
  }

  if (email.value === "") {
    email.setCustomValidity("Please enter your email address.");
    isValid = false;
  } else {
    email.setCustomValidity("");
  }

  if (phone.value === "" || phone.value.length < 10 || phone.value.length > 13 || isNaN(phone.value) || String(phone.value).startsWith("0")) {
    phone.setCustomValidity("Please enter your phone number.");
    isValid = false;
  } else {
    phone.setCustomValidity("");
  }

  let inquirySelected = false;
  for (let i = 0; i < inquiry.length; i++) {
    if (inquiry[i].checked) {
      inquirySelected = true;
      break;
    }
  }

  if (!inquirySelected) {
    inquiry[0].setCustomValidity("Please select an inquiry type.");
    isValid = false;
  } else {
    inquiry[0].setCustomValidity("");
  }

  if (message.value === "") {
    message.setCustomValidity("Please enter your message.");
    isValid = false;
  } else {
    message.setCustomValidity("");
  }

  return isValid;
}

// Form Submission
contactForm.addEventListener("submit", (e) => {
  if (validateForm()) {
    alert("Form submitted successfully!");
    contactForm.submit();
  } else {
    alert("Please fill in all required fields.");
    e.preventDefault();
    contactForm.reset();
    // location.reload();
  }
});