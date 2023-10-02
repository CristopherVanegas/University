
export default function Alerta({ alerta }) {
    return (
        <div className={`${alerta.error ? 'from-red-500 to-red-700' : 'from-sky-500 to-sky-700'} bg-gradient-to-br text-center p-3 rounded-xl uppercase text-white font-bold text-sm mb-5 mx-auto w-4/5 md:w-2/5`}>
            {alerta.msg}
        </div>
    );
}
