(function () {
    // Array of authorized domains
    var authorizedDomains = ['https://illyrius.me/AutoFrameCAD', 'https://github.com/illyrius666', 'https://github.com/illyrius666/AutoFrameCAD'];

    // Get the referring URL
    var referringURL = document.referrer;

    // Check if the referring URL is empty or not from an authorized domain
    if (referringURL !== '' && !authorizedDomains.some(function (domain) {
        return referringURL.includes(domain);
    })) {
        // Redirect or display an alternative image
        window.location.href = './hotlinking-error.html';
        // Alternatively, you can replace the image source with a placeholder image
        // var imageElement = document.getElementById('my-image');
        // imageElement.src = 'placeholder.jpg';
    }
})();
