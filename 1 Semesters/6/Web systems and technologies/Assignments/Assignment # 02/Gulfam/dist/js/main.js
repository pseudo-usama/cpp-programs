/**
 * MODAL
 */
var imgHeader = document.querySelector('#imgHeader');
var imgModal = document.querySelector('#imgModal');
var modelContent = document.querySelector('#modelContent');
var imgCaptionText = document.querySelector('#caption');

// IMG CLICLED
imgHeader.addEventListener('click', function () {
  imgModal.style.display = 'block';
  modalContent.src = this.src;
  imgCaptionText.innerHTML = this.alt;
});

// SPAN CLICK
document.querySelector('.close').addEventListener('click', function () {
  imgModal.style.display = 'none';
});

/**
 * Side Nav on MouseOver
 * JS
 */

var group = document.querySelectorAll('.groupSideNav a');
for (let i = 0; i < group.length; i++) {
  // MouseOver
  group[i].addEventListener('mouseover', () =>
    sideNavPosition(group[i], 0, 150)
  );
  // Mouse Leave
  group[i].addEventListener('mouseout', () =>
    sideNavPosition(group[i], -150, 200)
  );
}
function sideNavPosition(User, leftPosition, boxWidth) {
  User.style.left = leftPosition.toString() + 'px';
  User.style.width = boxWidth.toString() + 'px';
}

/**
 * Sticky Navbar
 */
var navbar = document.querySelector('nav');
var ofsetPosition = navbar.offsetTop;
window.onscroll = () => {
  if (window.pageYOffset >= ofsetPosition) {
    navbar.classList.add('sticky');
  } else {
    navbar.classList.remove('sticky');
  }
};

/**
 * DropDown Click Navigation
 */

var dropdownItem = document.querySelector('#dropdownItem');
var dropdownMenu = document.querySelector('#dropdownMenu');

dropdownItem.addEventListener('click', () => {
  dropdownMenu.classList.toggle('d-block');
  dropdownItem.classList.toggle('active');
});
