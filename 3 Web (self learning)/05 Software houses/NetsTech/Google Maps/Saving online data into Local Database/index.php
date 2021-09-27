<!DOCTYPE html>
<html>

<head>
    <title>Simple Map</title>
    <meta name="viewport" content="initial-scale=1.0">
    <meta charset="utf-8">

    <link rel="stylesheet" href="style.css">
    <script
        src="https://maps.googleapis.com/maps/api/js?key=YOUR_KEY&callback=initMap&libraries=places,geometry"
        async defer></script>

    <!-- Font Awesome CDN -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">
</head>

<body>
    <div id="side-bar">
        <button onclick="hideSideBar();"><i class="fa fa-caret-left" id="hide-show"></i></button>

        <div id="options">
            <p>Options</p>

            <table id="option-table">
                <tbody>
                    <tr>
                        <td>
                            <label class="chk-box">
                                <input type="checkbox" name="check" id="chk-box-all" onclick="checkUncheckAll();" />
                                <span>All</span>
                            </label>
                        </td>
                    </tr>

                    <tr>
                        <td>
                            <label class="chk-box">
                                <input type="checkbox" name="check" value="school" onclick="updateTypes(this);" />
                                <span>School</span>
                            </label>
                        </td>
                        <td>
                            <label class="chk-box">
                                <input type="checkbox" name="check" value="hospital" onclick="updateTypes(this);" />
                                <span>Hospital</span>
                            </label>
                        </td>
                        <td>
                            <label class="chk-box">
                                <input type="checkbox" name="check" value="mosque" onclick="updateTypes(this);" />
                                <span>Mosque</span>
                            </label>
                        </td>
                    </tr>

                    <tr>
                        <td>
                            <label class="chk-box">
                                <input type="checkbox" name="check" value="park" onclick="updateTypes(this);" />
                                <span>Park</span>
                            </label>
                        </td>
                        <td>
                            <label class="chk-box">
                                <input type="checkbox" name="check" value="gym" onclick="updateTypes(this);" />
                                <span>Gym</span>
                            </label>
                        </td>
                        <td>
                            <label class="chk-box">
                                <input type="checkbox" name="check" value="store" onclick="updateTypes(this);" />
                                <span>Store</span>
                            </label>
                        </td>
                    </tr>
                </tbody>
            </table>
        </div>
    </div>
    
    <div id="map"></div>


    <script>
        var placesTypes = [];    // Used in loadNearbyPlaces
    </script>

    <script>
        var map;
        var service;
        var infowindow;

        function initMap() {
            infowindow = new google.maps.InfoWindow();

            map = new google.maps.Map(document.getElementById('map'), {
                center: new google.maps.LatLng(33.720001, 73.059998),
                zoom: 10,
                disableDefaultUI: false,
                mapTypeId: google.maps.MapTypeId.ROADMAP
            });

            google.maps.event.addListener(map, 'mouseup', loadNearbyPlaces);   // Draging
            google.maps.event.addListener(map, 'zoom_changed', loadNearbyPlaces);    // Zooming
        }

        function loadNearbyPlaces() {
            if (placesTypes.length == 0)
                return;

            var request = {
                location: {
                    lat: map.getCenter().lat(),
                    lng: map.getCenter().lng()
                },
                radius: google.maps.geometry.spherical.computeDistanceBetween(map.getBounds().getSouthWest(), map.getBounds().getNorthEast()) / 2,
                type: placesTypes
            };

            service = new google.maps.places.PlacesService(map);
            service.nearbySearch(request, loadResultsinSidebar);
        }

        // This function create Markers on Map
        function createMarker(place) {
            var marker = new google.maps.Marker({
                map: map,
                position: place.geometry.location,
                icon: {
                    url: place.icon,
                    scaledSize: new google.maps.Size(20, 20)
                }
            });

            google.maps.event.addListener(marker, 'click', function () {
                infowindow.setContent(place.name);
                infowindow.open(map, this);
            });
        }

        function loadResultsinSidebar(results, status) {
            if (status == google.maps.places.PlacesServiceStatus.OK) {
                for (var i = 0; i < results.length; i++) {
                    createMarker(results[i]);

                    xmlhttp = new XMLHttpRequest();
                    xmlhttp.onreadystatechange = function() {
                        if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
                            if (this.responseText == 0) {
                                console.log("Insertion Successfull	:)");
                            }
                            else {
                                console.log("Insertion Failed		:(");
                            }
                            console.log(this.responseText);
                        }
                    }
                    xmlhttp.open('GET', `save_data.php?id=${results[i].id}&name=${results[i].name}&lat=${results[i].geometry.location.lat()}&lng=${results[i].geometry.location.lng()}&icon=${results[i].icon}`, true);
                    xmlhttp.send();                    
                }
            }
        }
    </script>

    <script>
        function hideSideBar() {
            if (document.getElementById('side-bar').offsetWidth != 0) {
                document.getElementById('side-bar').style.width = "0";
                document.getElementById('map').style.width = "100%";

                document.getElementById('hide-show').classList.remove('fa-caret-left');
                document.getElementById('hide-show').classList.add('fa-caret-right');
            }
            else {
                document.getElementById('side-bar').style.width = "20%";
                document.getElementById('map').style.width = "80%";

                document.getElementById('hide-show').classList.remove('fa-caret-right');
                document.getElementById('hide-show').classList.add('fa-caret-left');

                loadNearbyPlaces();
            }
        }



        function checkUncheckAll() {
            var chkBoxs = document.querySelectorAll('input[type=checkbox]');

            if (document.getElementById('chk-box-all').checked) {
                placesTypes = ['school', 'hospital', 'masque', 'park', 'gym', 'store'];

                for (var i in chkBoxs)
                    chkBoxs[i].checked = true;
            }
            else {
                placesTypes = [];

                for (var i in chkBoxs)
                    chkBoxs[i].checked = false;
            }
        }

        function updateTypes(clickedElem) {
            if (clickedElem.checked) {
                placesTypes.push(clickedElem.value);

                var chkBoxs = document.querySelectorAll('input[type=checkbox]');

                for (let i = 1; i < chkBoxs.length; i++) {
                    if (chkBoxs[i].checked == false)
                        return;
                }
                document.getElementById('chk-box-all').checked = true;
            }
            else {
                placesTypes = placesTypes.filter(e => e !== clickedElem.value);

                document.getElementById('chk-box-all').checked = false;
            }
        }
    </script>

</body>

</html>