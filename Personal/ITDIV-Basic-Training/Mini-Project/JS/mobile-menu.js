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