export default function Costos({titulo, valor}) {
    return (
        <div className="flex justify-between text-gray-500">
            <p>{titulo}</p>
            <p>USD {`${valor}`}</p>
        </div>
    )
}
