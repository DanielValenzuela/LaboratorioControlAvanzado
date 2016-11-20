function loadData(NAMEDATA,OPTION)
%% loadData(nameData,option)
%
%           NAMEDATA: nombre del archivo, NADA MAS si es que se encuentra
%                     dentro de la carpeta experiencia 3 o 4.
%
%           OPTION: 0 si solo carga los datos, 1 si grafica genericamente

clc
close all
try
           a=load(strcat('DATOS/',NAMEDATA));
           fields = fieldnames(a);
           for i =1:numel(fields)
               assignin('base',fields{i},eval(strcat('a.',fields{i})));
                if(OPTION)
                     graphInTime(eval(strcat('a.',fields{i},'.time')), eval(strcat('a.',fields{i},'.signals.values')), 'TITULO' , [0 160], 'b',1, 'b');
                end

           end 
catch ME
    if (strcmp(ME.identifier,'MATLAB:load:couldNotReadFile'))
        try
           a=load(NAMEDATA);
           fields = fieldsnames(a);
           for i =1:numel(fields)
               assignin('base',strcat(fields{i}),a.fields{i});
               if(OPTION)
                   graphInTime(eval(strcat('a.',fields{i},'.time')), eval(strcat('a.',fields{i},'.signals.values')), 'TITULO' , [0 160], 'b',1, 'b');
               end    
           end
        catch MF
            if (strcmp(MF.identifier,'MATLAB:load:couldNotReadFile'))

                error('No se encontro el archivo en la carpeta experiencia3!')
            end
        end    
    end       
end
 
    

    
end

