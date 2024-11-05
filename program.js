const buttons = document.querySelectorAll('.button');

buttons.forEach((button) => {
  button.addEventListener('mouseover', () => {
    button.style.transform = 'scale(1.1)';
    button.style.transition = 'all 0.3s ease';
  });

  button.addEventListener('mouseout', () => {
    button.style.transform = 'scale(1)';
    button.style.transition = 'all 0.3s ease';
  });
});

// Add active class to current button
buttons.forEach((button) => {
  button.addEventListener('click', () => {
    buttons.forEach((btn) => btn.classList.remove('active'));
    button.classList.add('active');
  });
});
