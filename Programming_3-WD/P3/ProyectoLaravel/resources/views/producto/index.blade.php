

<html>
    <body>
        <h1>Hello,</h1>
        
		@foreach ($productos as $producto)
		    <li>{{$producto->nombre}}</li>
		@endforeach
        
        
    </body>
</html>
