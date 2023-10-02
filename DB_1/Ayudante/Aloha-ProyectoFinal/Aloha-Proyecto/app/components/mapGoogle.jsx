import React from 'react';
import { useState, useEffect } from 'react';
import { GoogleMap, useJsApiLoader, Marker } from '@react-google-maps/api';

function Map({ setPositionUser, positionUser }) {

  const [position, setPosition] = useState({});

  const { isLoaded } = useJsApiLoader({
    id: 'google-map-script',
    googleMapsApiKey: "AIzaSyDjdD8F2lfmPwLu15dp0sYjTGCiAs5lnOA"
  });

  const containerStyle = {
    width: "80%",
    height: "400px",
    margin: "0 auto"
  };

  const center = {
    lat: positionUser.lat,
    lng: positionUser.lng
  };

  const handleMarkerDragEnd = (event) => {
    const { latLng } = event;
    const lat = latLng.lat();
    const lng = latLng.lng();
    setPosition({ lat, lng });
    setPositionUser({ lat, lng })
  };

  const [map, setMap] = React.useState(null);

  const onLoad = React.useCallback(function callback(map) {
    // This is just an example of getting and using the map instance!!! don't just blindly copy!
    const bounds = new window.google.maps.LatLngBounds(center);
    map.fitBounds(bounds);

    setMap(map);
  }, []);

  const onUnmount = React.useCallback(function callback(map) {
    setMap(null);
  }, []);

  return isLoaded ? (
    <GoogleMap
      mapContainerStyle={containerStyle}
      center={center}
      zoom={19}
      onLoad={onLoad}
      onUnmount={onUnmount}
    >
      <Marker position={center} draggable={true} onDragEnd={handleMarkerDragEnd} />
    </GoogleMap>
  ) : <></>;
}

export default React.memo(Map);
