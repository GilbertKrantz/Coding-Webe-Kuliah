// Please see documentation at https://docs.microsoft.com/aspnet/core/client-side/bundling-and-minification
// for details on configuring this project to bundle and minify static web assets.

// Write your JavaScript code.

// Haburger Menu
const menuBtn = document.querySelector('.menu-btn');
const Nav = document.querySelector('.nav');
const links = document.querySelectorAll('.link');
let menuOpen = false;
menuBtn.addEventListener('click', () => {
    if(!menuOpen){
    menuBtn.classList.add('open');
Nav.classList.add('open');
menuOpen = true;
    }else{
    menuBtn.classList.remove('open');
Nav.classList.remove('open');
menuOpen = false;
    }
});
links.forEach(link => {
    link.addEventListener('click', () => {
        menuBtn.classList.remove('open');
        Nav.classList.remove('open');
        menuOpen = false;
    });
});